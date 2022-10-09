// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
string s;
short d[5005][5005];
int sol[5005];
int rankk[5005];

int cmp(int l1, int r1, int l2, int r2) {
    int dl = min(r1-l1, r2-l2);
    int w = d[l1][l2];
    if (w < dl) {
        return s[l1+w] - s[l2+w];
    } else {
        return (r1-l1) - (r2-l2);
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i=n; i>=0; i--) {
            for (int j=n; j>=0; j--) {
                if (max(i, j) == n) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = s[i] == s[j] ? d[i+1][j+1] + 1 : 0;
                }
            }
        }

        vector<int> suff(n);
        iota(begin(suff), end(suff), 0);
        sort(begin(suff), end(suff), [&](int i, int j) {
            return cmp(i, n, j, n) < 0;
        });

        for (int i=0; i<n; i++) {
            rankk[suff[i]] = i;
        }

        vector<int> ss;
        sol[0] = n;
        for (int i=1; i<n; i++) {
            // add last suffix
            ss.push_back(i-1);
            int j = ss.size() - 1;
            while (j > 0 && rankk[ss[j]] < rankk[ss[j-1]]) {
                swap(ss[j], ss[j-1]);
                j--;
            }

            j = 0;
            int h = 0;
            sol[i] = 0;
            for (int len=1; len<=n-i; len++) {
                while (j < (int)ss.size() && cmp(ss[j], n, i, i + len) < 0) {
                    h = max(h, sol[ss[j]]);
                    j++;
                }
                sol[i] = max(sol[i], n-i-len+1+h);
            }
        }

        cout << *max_element(sol, sol+n) << '\n';
    }
}