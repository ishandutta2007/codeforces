#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
const int M = 7100;
const int B = 20;
const int C = B + 2;

int cn, cm, ns;
int flo[N], fhi[N];
int s[M];
int nt[C][N];

vector<int> l[M], r[M], x[M];

int main() {
    ios_base::sync_with_stdio(0);
    nt[0][0] = 0;
    nt[0][1] = 1;
    for (int i = 2; i < N; ++i) {
        int l = nt[0][i - 1];
        nt[0][i] = l + ((l & (l - 1)) || (l == nt[0][i - 2]));
    }
    for (int i = 1; i < N; ++i) {
        if (nt[0][i] != nt[0][i - 1]) {
            flo[nt[0][i]] = i;
            fhi[nt[0][i - 1]] = i - 1;
        }
    }
    for (int i = 0; i < B; ++i)
        for (int j = 1; j < N; ++j) nt[i + 1][j] = nt[i][nt[i][j]];
    cin >> cn >> cm;
    for (int m = 0; m < cm; ++m) {
        int type;
        cin >> type;
        if (type == 1) {
            int t, lx, rx, xx;
            cin >> t >> lx >> rx >> xx;
            l[t].push_back(lx);
            r[t].push_back(rx);
            x[t].push_back(xx);
        } else {
            int t, vlo, vhi;
            cin >> t >> vlo;
            vhi = vlo;
            ns = 0;
            for (int i = t; i <= cn; ++i) {
                for (int j = 0; j < l[i].size(); ++j) {
                    if (l[i][j] <= vhi && vlo <= r[i][j]) {
                        s[ns] = x[i][j];
                        ++ns;
                    }
                }
                vlo = flo[vlo];
                vhi = fhi[vhi];
            }
            if (ns == 0) {
                cout << "0\n";
                continue;
            }
            sort(s, s + ns);
            int ans = 1;
            for (int i = 1; i < ns; ++i) {
                if (s[i] != s[i - 1]) ++ans;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}