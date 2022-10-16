#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int x, y, a, b, n;
    cin >> x >> y >> a >> b >> n;
    int tot = x + y;
    int mx = x * a + y * b;
    if(mx - n >= tot) cout << "0 ";
    else cout << tot - mx + n << ' ';
    int t;
    if(a > b) {
        t = a; a = b; b = t;
        t = x; x = y; y = t;
    }
    int ans = 0;
    int k = n / a;
    if(k > x) k = x;
    ans += k;
    n -= k * a;
    k = n / b;
    ans += k;
    cout << ans << '\n';
    return 0;
}