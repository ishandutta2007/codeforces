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


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		vector<vector<int>> e(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			in >> a >> b;
			--a; --b;
			if (a != b)
				e[a].push_back(b);
		}
		vector<int> ce(n, -n);
		for (int i = 0; i < n; ++i) {
			sort(e[i].begin(), e[i].end());
			if (e[i].empty()) {
				continue;
			}
			e[i].push_back(e[i].front() + n);
			ce[i] = (e[i].size() - 2) * n + *upper_bound(e[i].begin(), e[i].end(), i) - i;
		}
		vector<int> res(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				res[i] = max(res[i], j + ce[(i + j) % n]);
			}
		}
		for (int i = 0; i < n; ++i) {
			out << res[i] << " ";
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