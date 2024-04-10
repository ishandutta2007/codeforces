#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    ld p;
    int t;
    cin >> n >> p >> t;
    ld q = 1 - p;
    vector<ld> v(n + 1, 0);
    v[0] = 1;
    ld carry;
    ld carry2;
    for(int i = 0; i < t; ++i){
        carry = 0;
        for(int j = 0; j <= n; ++j){
            if(j == n){
                v[j] = v[j] + carry;
            }else{
                carry2 = v[j] * p;
                v[j] = v[j] * q + carry;
                carry = carry2;
            }
        }
    }
    ld ans = 0;
    for(int i = 0; i <= n; ++i){
        ans += v[i] * i;
    }
    cout << setprecision(15) << fixed << ans << endl;
}