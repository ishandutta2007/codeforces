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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n), x(n), y(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        ll now = 0;
        for(int i = 0; i < n; i++) {
            x[i] = min(a[i], m);
            y[i] = m - x[i];
            now += (a[i] - x[i]) - (b[i] - y[i]);
        }
        for(int i = 0; i < n; i++) {
            if(now >= -1) {
                break;
            }
            ll good = abs(now) / 2;
            ll can = min(b[i] - y[i], x[i]);
            ll here = min(can, good);
            x[i] -= here;
            y[i] += here;
            now += here * 2;
        }
        cout << abs(now) << '\n';
        for(int i = 0; i < n; i++) {
            cout << x[i] << ' ' << y[i] << '\n';
        }
    }
}