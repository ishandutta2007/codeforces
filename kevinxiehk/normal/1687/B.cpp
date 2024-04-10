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
int ask(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}
void answer(int x) {
    cout << "! " << x << endl;
    return;
}
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    pair<int, int> arr[m + 5];
    int ans = 0;
    string s = "";
    for(int i = 0; i < m; i++) s += '0';
    for(int i = 0; i < m; i++) {
        s[i] = '1';
        arr[i].fi = ask(s);
        arr[i].se = i;
        s[i] = '0';
    }
    s = "";
    sort(arr, arr + m);
    reverse(arr, arr + m);
    for(int i = 0; i < m; i++) s += '1';
    int last = ask(s);
    for(int i = 0; i < m - 1; i++) {
        s[arr[i].se] = '0';
        int t = ask(s);
        if(t + arr[i].fi == last) {
            ans += arr[i].fi;
        } 
        last = t;
    }
    ans += arr[m - 1].fi;
    answer(ans);
}
signed main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}