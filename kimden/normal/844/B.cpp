#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int x;
    vector<int> r(n, 0), c(m, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> x;
            if(x){
                ++r[i], ++c[j];
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans += (1LL << ll(r[i])) + (1LL << ll(m - r[i])) - 2;
    }
    for(int i = 0; i < m; ++i){
        ans += (1LL << ll(c[i])) + (1LL << ll(n - c[i])) - 2;
    }
    ans -= n * m;
    cout << ans << endl;
}