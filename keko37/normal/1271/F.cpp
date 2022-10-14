#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t;
int a1, b1, c1, a2, b2, c2;
int d1, d2, d3, d4, d5, d6, d7;
int x1, x2, x3, x4, x5, x6, x7;
int a_lo, b_lo, c_lo;

bool check () {return x1 <= d1 && x2 <= d2 && x3 <= d3 && x4 <= d4 && x5 <= d5 && x6 <= d6 && x7 <= d7;}
bool check_a () {return a_lo <= x1 + x2 + x3 + x4 && x1 + x2 + x3 + x4 <= a1;}
bool check_b () {return b_lo <= x1 + x2 + x5 + x6 && x1 + x2 + x5 + x6 <= b1;}
bool check_c () {return c_lo <= x1 + x3 + x5 + x7 && x1 + x3 + x5 + x7 <= c1;}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7;
        a_lo = d1 + d2 + d3 + d4 - a2;
        b_lo = d1 + d2 + d5 + d6 - b2;
        c_lo = d1 + d3 + d5 + d7 - c2;
        bool naso = 0;
        for (x2 = 0; x2 <= d2; x2++) {
            for (x3 = 0; x3 <= d3; x3++) {
                x1 = max(a_lo - (x2 + x3 + d4), 0);
                x5 = max(max(b_lo - (x2 + x1 + d6), c_lo - (x3 + x1 + d7)), 0);
                if (x5 > d5) {
                    x1 += x5 - d5;
                    x5 = d5;
                }
                x4 = max(a_lo - (x2 + x3 + x1), 0);
                x6 = max(b_lo - (x2 + x5 + x1), 0);
                x7 = max(c_lo - (x3 + x5 + x1), 0);
                if (check() && check_a() && check_b() && check_c()) {naso = 1; break;}
            }
            if (naso) break;
        }
        if (!naso) cout << "-1\n"; else cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << x6 << " " << x7 << '\n';
    }
    return 0;
}