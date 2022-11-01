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
        int n;
        in >> n;
        vector<vector<int64_t>> a(n, vector<int64_t>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + j != 0 && i + j != 2 * n && i % 2 == 0)
                    a[i][j] = 1LL << (i + j - 1);
                out << a[i][j] << " ";
            }
            out << endl;
        }
        out.flush();
        int q;
        in >> q;
        while (q--) {
            int64_t k;
            in >> k;
            vector<pair<int, int>> res;
            res.push_back(make_pair(0, 0));
            while (res.size() != 2 * n - 1) {
                int px = res.back().first;
                int py = res.back().second;
                if (px == n - 1) {
                    res.push_back(make_pair(px, py + 1));
                    continue;
                }
                if (py == n - 1) {
                    res.push_back(make_pair(px + 1, py));
                    continue;
                }
                if (a[px + 1][py]) {
                    if (k & a[px + 1][py]) {
                        res.push_back(make_pair(px + 1, py));
                    }
                    else {
                        res.push_back(make_pair(px, py + 1));
                    }
                }
                else {
                    if (k & a[px][py + 1]) {
                        res.push_back(make_pair(px, py + 1));
                    }
                    else {
                        res.push_back(make_pair(px + 1, py));
                    }
                }
            }
            for (const auto& r : res) {
                out << r.first + 1 << " " << r.second + 1 << endl;
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
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}