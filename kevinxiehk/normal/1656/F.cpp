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
void gay(int TC) {cout << "Case #" << TC << ": ";}
int dsu[200005];
int f(int x) {
    if(dsu[x] == x) return x;
    return f(dsu[x]);
}
int arr[200005];
int n;
int calc(int t) {
    int ans = 0;
    int mx = arr[0], mi = arr[0];
    int lpt = 1, rpt = n - 1;
    for(int i = 1; i < n; i++) {
        int connl = min(arr[lpt] * (mi + t) + mi * t, arr[lpt] * (mx + t) + mx * t);
        int connr = min(arr[rpt] * (mi + t) + mi * t, arr[rpt] * (mx + t) + mx * t);
        if(connl < connr) {
            ans += connl;
            mx = max(mx, arr[lpt]);
            lpt++;
        }
        else {
            ans += connr;
            mx = max(mx, arr[rpt]);
            rpt--;
        }
    }
    return ans;
}
void solve(int TC) {
    // int n;
    cin >> n;   
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = -1e7, r = 1e7;
    while(l < r) {

        // cerr << l << ' ' << r << '\n';

        int d = r - l;
        int m = l + d / 2;

        if(calc(m) < calc(m + 1)) l = m + 1;
        else r = m;
        // cerr << l << ' ' << r << ' ' << calc(m) << '\n';
    }
    if(abs(l) == 1e7 && calc(l) != calc(l + 1)) {
        cout << "INF\n";
    }
    else cout << calc(l) << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}