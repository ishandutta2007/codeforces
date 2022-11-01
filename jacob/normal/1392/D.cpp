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
    static int hammingAtPos(const string& s, int pos, const string& pat) {
        int res = 0;
        for (int i = 0; i < pat.size(); ++i) {
            if (s[pos - pat.size() + i] != pat[i])
                ++res;
        }
        return res;
    }

    void solve(std::istream& in, std::ostream& out) {
        static const string LR = "LR";
        static const string LLR = "LLR";
        static const string LRR = "LRR";
        static const string LLRR = "LLRR";
        int n; in >> n;
        string s; in >> s;
        int bestRes = n;
        for (int i = 0; i < 4; ++i) {
            s = s.substr(1) + s[0];
            vector<int> d(n + 1, n);
            d[0] = 0;
            for (int j = 2; j <= n; ++j) {
                d[j] = min(d[j], d[j - 2] + hammingAtPos(s, j, LR));
                if (j >= 3) {
                    d[j] = min(d[j], d[j - 3] + hammingAtPos(s, j, LLR));
                    d[j] = min(d[j], d[j - 3] + hammingAtPos(s, j, LRR));
                }
                if (j >= 4) {
                    d[j] = min(d[j], d[j - 4] + hammingAtPos(s, j, LLRR));
                }
            }
            bestRes = min(bestRes, d[n]);
        }
        out << bestRes << endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    int t;
    in >> t;
    while (t--) {
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