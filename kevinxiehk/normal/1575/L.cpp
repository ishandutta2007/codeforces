#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
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
void gay(int TC) {cout << "Case #" << TC << ": ";}
struct pe{
    int v;
    int id;
} a[200005];
int b[200005];
bool cmp(pe x, pe y) {
    if(x.v == y.v)return x.id < y.id;
    return x.v < y.v;
}
int d[200005];
int cnt;
int n;
bool can(int k) {
    //sort(a+1,a+1+n,cmp);
    int pos;
    cnt = 0;
    for(int i = 0; i < n; i++) d[i] = 0;
    for(int i = 1; i < n; i++) {
        if(a[i].v >= 0){
            pos = i;
            break;
        }
    }
    for(int i = pos; i < n; i++) {
          //  if(a[i].v)
        // printf("%lld ",a[i].v);
        if(cnt == 0 || a[i].id > d[cnt]) {
            d[++cnt] = a[i].id;
        }
        else{
            int k = lower_bound(d + 1, d + 1 + cnt, a[i].id) - d;
            if(k >= 0) d[k] = a[i].id;
        }
        if(cnt >= k) return true;
    }
    return false;
}
void solve(int TC) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        if(b[i] > n) {
            b[i] = n + 1;
        }
        a[i].v = i - b[i];
        a[i].id = b[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    int l = 0, r = n;
    n++;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(!can(m)) r = m - 1;
        else l = m;
    }
    cout << l << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}