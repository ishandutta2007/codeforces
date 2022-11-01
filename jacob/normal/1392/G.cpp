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
#include <bitset>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


using bs20 = bitset <20>;

class Solution {
public:
    bs20 readBs(std::istream& in) {
        string s;
        in >> s;
        bs20 res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                res[i] = true;
        }
        return res;
    }

    vector<unsigned> masksBeg, masksEnd;
    vector<char> precalcBitCount;
    vector< vector<int> > leftmost;

    void solve(std::istream& in, std::ostream& out) {
        int n, m, k;
        in >> n >> m >> k;
        int p2k = (1 << k);
        precalcBitCount.resize(p2k);
        for (int i = 0; i < precalcBitCount.size(); ++i) {
            precalcBitCount[i] = bs20(i).count();
        }
        vector<int> a(n), b(n);
        bs20 beg = readBs(in);
        bs20 end = readBs(in);
        for (int i = 0; i < n; ++i) {
            in >> a[i] >> b[i];
            --a[i]; --b[i];
        }
        masksBeg.resize(n + 1);
        masksBeg[n] = beg.to_ulong();
        masksEnd.resize(n + 1);
        masksEnd[n] = end.to_ulong();
        vector<int> perm(k);
        for (int i = 0; i < k; ++i)
            perm[i] = i;
        for (int i = n - 1; i >= 0; --i) {
            int pa = perm[a[i]];
            int pb = perm[b[i]];
            if (beg[pa] != beg[pb]) {
                beg.flip(pa);
                beg.flip(pb);
            }
            if (end[pa] != end[pb]) {
                end.flip(pa);
                end.flip(pb);
            }
            swap(perm[a[i]], perm[b[i]]);
            masksBeg[i] = beg.to_ulong();
            masksEnd[i] = end.to_ulong();
        }

        int bestDiff = k + 1;
        int resi = -1, resj = -1;

        if (true) {
            leftmost.resize(k + 1, vector<int>(p2k, n + 1));
            for (int i = n; i >= 0; --i) {
                leftmost[0][masksBeg[i]] = i;
            }

            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < p2k; ++j) {
                    leftmost[i + 1][j] = leftmost[i][j];
                }
                for (int j = 0; j < p2k; ++j) {
                    if (leftmost[i][j] != n + 1) {
                        for (int bitind = 0; bitind < k; ++bitind) {
                            int& nv = leftmost[i + 1][j ^ (1 << bitind)];
                            nv = min(nv, leftmost[i][j]);
                        }
                    }
                }
            }


            for (int i = m; i <= n; ++i) {
                int d = 0;
                while (leftmost[d][masksEnd[i]] > i - m)
                    ++d;

                int j = leftmost[d][masksEnd[i]];
                if (bestDiff > d) {
                    bestDiff = d;
                    resi = i;
                    resj = leftmost[d][masksEnd[i]];
                }
            }
        }
        else {
            for (int i = m; i <= n; ++i) {
                for (int j = 0; j <= i - m; ++j) {
                    int cDiff = precalcBitCount[masksBeg[j] ^ masksEnd[i]];
                    if (cDiff < bestDiff) {
                        bestDiff = cDiff;
                        resi = i; resj = j;
                    }
                }
            }
        }
        
        out << k - bestDiff << endl << resj + 1 << " " << resi << endl;
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