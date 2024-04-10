#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

template<class Queue>
    void copyQueue(Queue &src, Queue &dest) {
        while (!src.empty()) {
            dest.push(src.top()); src.pop();
        }
    }

class Node {
public:
    int depth;
    bool hasWord;
    Node* children[26];
    priority_queue<pair<int, Node*> >* subtree;

    Node() {
        depth = 0;
        hasWord = false;
        REP(i, 26) children[i] = NULL;
        subtree = NULL;
    }

    void adjust(void) {
        bool isLeaf = true;
        REP(i, 26) if (children[i] != NULL) isLeaf = false;
        if (isLeaf) {
            assert(hasWord);
            subtree = new priority_queue<pair<int, Node*> >();
            subtree->push(make_pair(depth, this));
            return;
        }

        REP(i, 26) if (children[i] != NULL) {
            children[i]->adjust();
            if (subtree == NULL || subtree->size() < children[i]->subtree->size())
                subtree = children[i]->subtree;
        }

        REP(i, 26) if (children[i] != NULL && subtree != children[i]->subtree)
            copyQueue(*(children[i]->subtree), *subtree);

        if (!hasWord) subtree->pop();
        subtree->push(make_pair(depth, this));
    }

    long long sumLength(void) {
        long long res = 0;
        while (!subtree->empty()) {
            res += subtree->top().fi; subtree->pop();
        }
        return res;
    }
};

Node* root;
void addWord(const string &word) {
    Node* p = root;
    FORE(it, word) {
        if (p->children[*it - 'a'] == NULL) {
            p->children[*it - 'a'] = new Node();
            p->children[*it - 'a']->depth = p->depth + 1;
        }
        p = p->children[*it - 'a'];
    }
    p->hasWord = true;
}

void process(void) {
    root = new Node();

    int numWord; cin >> numWord;
    REP(aye, numWord) {
        string word; cin >> word;
        addWord(word);
    }

    long long res = 0;
    REP(i, 26) if (root->children[i] != NULL) {
        Node *p = root->children[i];
        p->adjust();
        res += p->sumLength();
    }
    cout << res << endl;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/