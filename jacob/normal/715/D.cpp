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
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


using door = tuple<int, int, int, int>;

class Solution {
public:
	void solve(std::istream& in, std::ostream& out) {
		long long n;
		in >> n;
		long long pow6 = 1;
		int sz = 2;
		while (3 * pow6 <= n) {
			pow6 *= 6;
			sz += 2;
		}
		vector<door> res;
		auto append_dual = [&](int x1, int y1, int x2, int y2) {
			res.emplace_back(x1, y1, x2, y2 );
			res.emplace_back(y1, x1, y2, x2);
		};
		for (int i = 4, j = 0; i < sz; i += 2, j += 2) {
			if (j != 0) {
				append_dual(i, j, i + 1, j);
			}
			append_dual(i, j + 1, i + 1, j + 1);
			//append_dual(i + 1, j + 1, i + 1, j + 2);
			//append_dual(i + 2, j + 1, i + 2, j + 2);
		}
		for (int i = 1; i <= sz - 3; i += 2) {
			if (i != 1) {
				append_dual(i - 1, i + 1, i, i + 1);
				append_dual(i - 1, i + 2, i, i + 2);
			}
			res.emplace_back(i + 1, i + 2, i + 1, i + 3);
			if (n % 6 < 3) {
				res.emplace_back(i + 2, i + 1, i + 3, i + 1);
			}
			if (n % 3 < 2) {
				res.emplace_back(i, i + 2, i, i + 3);
			}
			if (n % 3 < 1) {
				res.emplace_back(i + 2, i, i + 3, i);
			}
			n /= 6;
		}
		if (n <= 1) {
			res.emplace_back(sz - 1, sz - 1, sz, sz - 1);
		}
		if (n == 0) {
			res.emplace_back(sz - 1, sz - 1, sz - 1, sz);
		}
		out << sz << " " << sz << endl;
		out << res.size() << endl;
		for (auto item : res) {
			int x1, y1, x2, y2;
			tie(x1, y1, x2, y2) = item;
			out << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
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