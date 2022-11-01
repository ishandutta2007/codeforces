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


// Include this file in your solution cpp file like this: #include "example.h"

using pii = pair<int, int>;

class Solution {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m, q;
		in >> n >> m >> q;
		vector<vector<pii>> ma(n, vector<pii>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ma[i][j] = pii(i, j);
		vector< vector<int> > result(n, vector<int>(m));
		while (q--) {
			int t;
			in >> t;
			if (t == 3) {
				int r, c;
				int x;
				in >> r >> c >> x;
				--r; --c;
				pii coords = ma[r][c];
				result[coords.first][coords.second] = x;
			}
			else if (t == 2) {
				int c;
				in >> c;
				--c;
				for (int i = 1; i < n; ++i) {
					swap(ma[i - 1][c], ma[i][c]);
				}
			}
			else if (t == 1) {
				int r;
				in >> r;
				--r;
				for (int i = 1; i < m; ++i) {
					swap(ma[r][i - 1], ma[r][i]);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				out << result[i][j] << " ";
			}
			out << endl;
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