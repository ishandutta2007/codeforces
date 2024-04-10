#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <memory>
#include <vector>
#include <unordered_map>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


// Include this file in your solution cpp file like this: #include "example.h"

#define ALL(c) std::begin(c),std::end(c)
using pii = pair<int, int>;


#include <functional>
#include <iterator>
#include <cassert>


#include <limits>

namespace data_structures {
namespace interval_trees {

// Data should implement the following methods:
//   1) Copy constructor / operator=
//   2) Default constructor
template<class Data, bool is_commutative = false>
class SimpleIntervalTree {
public:
	using Operation = std::function<Data(const Data&, const Data&)>;
	SimpleIntervalTree(size_t size, Operation op, const Data& default_value) {
		op_ = op;
		size_ = size;
		capacity_ = size - 1;
		for (int shift = 1; shift < sizeof(capacity_); shift *= 2) {
			capacity_ |= capacity_ >> shift;
		}
		capacity_ += 1;
		tree_.assign(capacity_ * 2, default_value);
	}


	void AddAt(size_t offset, const Data& data, bool add_front=false) {
		assert(offset < size_);
		offset += capacity_;
		if (is_commutative) {
			// This means we can do everything "easy" way.
			while (offset != 0) {
				ApplyOp(tree_[offset], data, &tree_[offset]);
				//OptimizeChooser::Call(tree[offset]);
				offset /= 2;
			}
		}
		else {
			if (add_front) {
				ApplyOp(data, tree_[offset], &tree_[offset]);
			}
			else {
				ApplyOp(tree_[offset], data, &tree_[offset]);
			}
			while (offset != 1) {
				offset /= 2;
				Recompute(offset);
			}
		}
	}

	// left and right - inclusive
	Data RangeReduce(size_t left, size_t right) {
		assert(right < size_);
		assert(left <= right);
		left += capacity_;
		right += capacity_;
		if (left == right) {
			return tree_[left];
		}
		Data left_slope = tree_[left];
		Data right_slope = tree_[right];
		while (right - left != 1) {
			if (left % 2 == 0) {
				ApplyOp(left_slope, tree_[left + 1], &left_slope);
			}
			if (right % 2 == 1) {
				ApplyOp(tree_[right - 1], right_slope, &right_slope);
			}
			left /= 2;
			right /= 2;
		}
		ApplyOp(left_slope, right_slope, &left_slope);
		return left_slope;
	}

private:
	// To make it more flexible.
	void ApplyOp(const Data& left, const Data& right, Data* output) {
		*output = op_(left, right);
	}

	void Recompute(size_t offset) {
		ApplyOp(tree_[offset * 2], tree_[offset * 2 + 1], &tree_[offset]);
	}

	size_t capacity_;
	size_t size_;
	Operation op_;
	std::vector<Data> tree_;
};


}  // namespace interval_trees
}  // namespace data_structures

template<class T>
struct SumIntervalTree : public data_structures::interval_trees::SimpleIntervalTree<T, true>
{
	//using SimpleIntervalTree<T, true>::SimpleIntervalTree;
	SumIntervalTree(size_t size) : data_structures::interval_trees::SimpleIntervalTree<T, true>(
		size,
		[](const T& left, const T& right) {return left + right; },
		T())
	{}
};

struct Query {
	int a, t, x;
};

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		unordered_map<int, vector<int> > times_for_x;
		int n;
		in >> n;
		vector<Query> queries(n);
		for (auto &q : queries) {
			in >> q.a >> q.t >> q.x;
			times_for_x[q.x].push_back(q.t);
		}
		unordered_map<int, SumIntervalTree<int>*> tree_for_x;
		for (auto &kv : times_for_x) {
			sort(ALL(kv.second));
			kv.second.erase(unique(ALL(kv.second)), kv.second.end());
			tree_for_x[kv.first] = new SumIntervalTree<int>(kv.second.size());
		}
		for (const auto& q : queries) {
			const auto& rel_times = times_for_x[q.x];
			size_t index = lower_bound(ALL(rel_times), q.t) - rel_times.begin();
			auto& rel_tree = *(tree_for_x[q.x]);
			switch (q.a) {
			case 1:
				rel_tree.AddAt(index, 1);
				break;
			case 2:
				rel_tree.AddAt(index, -1);
				break;
			case 3:
				out << rel_tree.RangeReduce(0, index) << endl;
				break;
			}
		}
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
#include <fstream>
#include <iostream>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;
    solve(in, out);
    return 0;
}