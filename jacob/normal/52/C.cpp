#include <new>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>

namespace dlougach {
    namespace cartesian {

        namespace impl {
            template<class TNode>
            TNode* allocateNode()
            {
                return (TNode*) ::operator new(sizeof(TNode), std::nothrow);
            }

            template<class TNode>
            void deallocateNode(const TNode* p) {
                delete p;
            }

        } // namespace impl

        template<typename Tree>
        class CartesianTreeBase {
        public:
            typedef Tree* TreePtr;

            struct Iterator {
            private:
                std::vector<TreePtr> _stack;
                TreePtr _root;
            public:
                explicit Iterator(TreePtr root) {
                    _root = root;
                }

                void goLeft() {
                    assert(current()->hasLeft());
                    current()->propagateDown();
                    _stack.push_back(current()->getLeft());
                }
                void goRight() {
                    assert(current()->hasRight());
                    current()->propagateDown();
                    _stack.push_back(current()->getRight());
                }
                bool isEnd() {
                    return _stack.empty();
                }
                bool isTop() {
                    return (_stack.size() == 1);
                }
                TreePtr root() {
                    return _root;
                }
                bool goUp() /// returns true if we came from the right branch, false if we came from the left one
                { 
                    TreePtr p = _stack.back();
                    _stack.pop_back();
                    assert(!_stack.empty());
                    return (current()->getRight() == p);
                }

                void next() {
                    assert(!isEnd());
                    while (!current()->hasRight())
                        goUp();
                    goRight();
                    while (current()->hasLeft())
                        goLeft();
                }
                void prev() {
                    if (isEnd()) {
                        assert( !(_root == NULL) );
                        _stack.push_back(_root);
                    } else {
                        while (!current()->hasLeft())
                            goUp();
                        goLeft();
                    }
                    while (current->hasRight())
                        goRight();
                }

                TreePtr current() {
                    assert(!isEnd());
                    return _stack.back();
                }
                TreePtr operator->() {
                    return current();
                }
                Tree& operator*() {
                    return *current();
                }
                friend class CartesianTreeBase<Tree>;
            };

            // Basic helpers to view the tree
            bool hasLeft() const {
                return !(_left == NULL);
            }
            TreePtr getLeft() {
                return _left;
            }
            size_t getLeftSize() {
                return hasLeft() ? getLeft()->getSize() : 0;
            }
            bool hasRight() const {
                return !(_right == NULL);
            }
            TreePtr getRight() {
                return _right;
            }
            size_t getRightSize() {
                return hasRight() ? getRight()->getSize() : 0;
            }
            size_t getSize() {
                return _size;
            }

            // Basic helpers to change the tree
            void setLeft(TreePtr ptr) {
                This()->propagateDown();
                _left = ptr;
                This()->propagateUp();
            }
            void setRight(TreePtr ptr) {
                This()->propagateDown();
                _right = ptr;
                This()->propagateUp();
            }

            static std::pair<TreePtr, TreePtr> cutByIterator(Iterator &iter) {
                if (iter.isEnd()) {
                    return std::make_pair(iter.root(), TreePtr(NULL));
                }
                TreePtr left = iter->getLeft();
                TreePtr right = iter.current();
                right->setLeft(TreePtr(NULL));
                while (!iter.isTop()) {
                    if (iter.goUp()) {
                        iter.current()->setRight(left);
                        left = iter.current();
                    } else {
                        iter.current()->setLeft(right);
                        right = iter.current();
                    }
                }
                return std::make_pair(left, right);
            }

            std::pair<TreePtr, TreePtr> cutByPosition(size_t position) {
                Iterator iter = getIterator(position);
                return cutByIterator(iter);
            }

            static TreePtr glue(TreePtr left, TreePtr right) {
                if (left == NULL)
                    return right;
                if (right == NULL)
                    return left;
                unsigned r = rand() & 0xffff;
                r <<= 16;
                r |= rand() & 0xffff;
                r %= left->getSize() + right->getSize();
                left->propagateDown();
                right->propagateDown();
                TreePtr result;
                if (r < left->getSize()) {
                    result = left;
                    result->setRight(glue(result->getRight(), right));
                } else {
                    result = right;
                    result->setLeft(glue(left, right->getLeft()));
                }
                return result;
            }

            Iterator getIterator(size_t position) {
                Iterator result(This());
                assert(position <= getSize());
                if (position != getSize()) {
                    result._stack.push_back(This());
                    while (true) {
                        result->propagateDown();
                        size_t leftSize = 0;
                        if (result->hasLeft()) {
                            leftSize = result->getLeft()->getSize();
                        }
                        if (position == leftSize) {
                            break;
                        }
                        if (position < leftSize) {
                            result.goLeft();
                        } else {
                            result.goRight();
                            position -= leftSize + 1;
                        }
                    }
                }
                return result;
            }

            void propagateDown() {
            }
            void propagateUp() {
                _size = 1;
                _size += getLeftSize();
                _size += getRightSize();
            }

            CartesianTreeBase() {
                _left = _right = NULL;
                propagateUp();
            }
        private:
            size_t _size;
            TreePtr _left, _right;
        protected:
            TreePtr This() {
                return static_cast<TreePtr>(this);
            }

        };


        class SimpleCartesianTree: public CartesianTreeBase<SimpleCartesianTree> {};

        template<typename Tree, typename AlteringFunction>
        class RangeCartesianTree: public CartesianTreeBase<Tree>
        {
        public:
            typedef CartesianTreeBase<Tree> Base;
            AlteringFunction func;

            RangeCartesianTree() {
                func.reset();
            }

            void apply(const AlteringFunction& f) {
                func.apply(f);
                this->This()->applyToThis(f.skip(this->getLeftSize()));
            }

            void applyToThis(const AlteringFunction& f) {
            }

            void propagateDown() {
                Base::propagateDown();
                if (this->hasLeft()) {
                    this->getLeft()->apply(func);
                }
                if (this->hasRight()) {
                    this->getRight()->apply(func.skip(this->getLeftSize() + 1));
                }
                func.reset();
            }

        };

        struct IncrementFunction {
            long long incVal;

            IncrementFunction() {
                reset();
            }
            IncrementFunction(long long v)
                : incVal(v)
            {}

            void reset() {
                incVal = 0;
            }
            void apply(const IncrementFunction& other) {
                incVal += other.incVal;
            }
            IncrementFunction skip(size_t s) const {
                return *this;
            }
        };

        class IncMinCartesianTree: public RangeCartesianTree<IncMinCartesianTree, IncrementFunction>
        {
        public:
            typedef RangeCartesianTree<IncMinCartesianTree, IncrementFunction> Base;
            long long value;
            long long subTreeMinimum;

            void applyToThis(const IncrementFunction& f) {
                value += f.incVal;
                subTreeMinimum += f.incVal;
            }

            void propagateUp() {
                Base::propagateUp();
                subTreeMinimum = value;
                if (this->hasLeft()) {
                    subTreeMinimum = std::min(subTreeMinimum, this->getLeft()->subTreeMinimum);
                }
                if (this->hasRight()) {
                    subTreeMinimum = std::min(subTreeMinimum, this->getRight()->subTreeMinimum);
                }
            }
        };

    } // namespace cartesian
} // namespace dlougach
/**END include**/

//#include "cartesian_tree_base.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>

void TestCartesianTrees() {
    using namespace dlougach::cartesian;
    SimpleCartesianTree *tree1, *tree2;
    tree1 = new SimpleCartesianTree();
    tree2 = new SimpleCartesianTree();
    SimpleCartesianTree *tree3 = tree1->glue(tree1, tree2);
    if (tree3->getSize() != 2)
        abort();
    SimpleCartesianTree::Iterator it = tree3->getIterator(1);
    std::pair<SimpleCartesianTree::TreePtr, SimpleCartesianTree::TreePtr> pr = tree3->cutByIterator(it);
    if (pr.first != tree1)
        abort();
    if (pr.second != tree2)
        abort();
}

void Test_Codeforces_TestingRound1_ProblemC() {
    using namespace std;
    using namespace dlougach::cartesian;
    ios::sync_with_stdio(false);
    istringstream iss;
    string line;
    getline(cin, line);
    iss.str(line); iss.seekg(0); iss.clear();
    int n;
    iss >> n;
    vector<int> a(n);
    IncMinCartesianTree* tree = NULL;
    getline(cin, line);
    iss.str(line); iss.seekg(0); iss.clear();
    for (int i = 0; i < n; ++i) {
        iss >> a[i];
        IncMinCartesianTree* node = new IncMinCartesianTree();
        node->value = a[i];
        node->propagateUp();
        tree = IncMinCartesianTree::glue(tree, node);
    }
    getline(cin, line);
    iss.str(line); iss.seekg(0); iss.clear();
    int m;
    iss >> m;
    while (m--) {
        getline(cin, line);
        iss.str(line); iss.seekg(0); iss.clear();
        int lf, rg;
        iss >> lf >> rg;
        ++rg;
        pair<IncMinCartesianTree*, IncMinCartesianTree*> cut1 = tree->cutByPosition(max(lf, rg));
        pair<IncMinCartesianTree*, IncMinCartesianTree*> cut2 = cut1.first->cutByPosition(min(lf, rg));
        int v;
        if (iss >> v) {
            if (lf < rg) {
                cut2.second->apply(IncrementFunction(v));
            } else {
                if (cut2.first != NULL) {
                    cut2.first->apply(IncrementFunction(v));
                }
                if (cut1.second != NULL) {
                    cut1.second->apply(IncrementFunction(v));
                }
            }
        } else {
            if (lf < rg) {
                cout << cut2.second->subTreeMinimum << endl;
            } else {
                long long result = LLONG_MAX;
                if (cut2.first != NULL) {
                    result = min(result, cut2.first->subTreeMinimum);
                }
                if (cut1.second != NULL) {
                    result = min(result, cut1.second->subTreeMinimum);
                }
                cout << result << endl;
            }
        }
        tree = IncMinCartesianTree::glue(IncMinCartesianTree::glue(cut2.first, cut2.second), cut1.second);
    }
}

int main(void) {
    //TestCartesianTrees();
    Test_Codeforces_TestingRound1_ProblemC();
}