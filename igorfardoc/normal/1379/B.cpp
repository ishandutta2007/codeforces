#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        ll m;
        int l, r;
        cin >> l >> r >> m;
        bool ok = false;
        for(int n = 1; (ll)n * n <= m + 1000000; n++) {
            ll a = m / n;
            if(a > r) {
                a = r;
            } else if(a < l) {
                a = l;
            }
            if(abs(m - a * n) <= r - l) {
                ll c = l;
                ll b = l + abs(m - a * n);
                if(m - a * n < 0) {
                    swap(b, c);
                }
                cout << a << ' ' << b << ' ' << c << '\n';
                ok = true;
                break;
            }
        }
        if(ok) {
            continue;
        }
        for(int a = l; a <= r; a++) {
            ll n = m / a;
            if(n == 0 || abs(n * a - m) > abs((n + 1) * a - m)) {
                ++n;
            }
            if(abs(m - a * n) <= r - l) {
                ll c = l;
                ll b = l + abs(m - a * n);
                if(m - a * n < 0) {
                    swap(b, c);
                }
                cout << a << ' ' << b << ' ' << c << '\n';
                ok = true;
                break;
            }
        }
    }
}