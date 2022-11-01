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
        int64_t k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        if (k % 2 == 0) {
            int d = *min_element(a.begin(), a.end());
            for (int i = 0; i < n; ++i) {
                out << a[i] - d << " ";
            }
            out << endl;
        }
        else {
            int d = *max_element(a.begin(), a.end());
            for (int i = 0; i < n; ++i) {
                out << d - a[i] << " ";
            }
            out << endl;
        }
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    int T;
    in >> T;
    while (T--) {
        Solution solution;
        solution.solve(in, out);
    }
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