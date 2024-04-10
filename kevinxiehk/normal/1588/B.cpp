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
int ask(int a, int b) {
    if(a >= b) return 0;
    cout << "? " << a << ' ' << b << endl;
    int ans;
    cin >> ans;
    return ans;
}
void solve(int TC) {
    int n;
    cin >> n;
    int tot = ask(1, n);
    int l = 1, r = n;
    int ll = tot, rr, lid, rid, rrid;
    while(l < r) {
        int m = (l + r) / 2;
        int k = ask(1, m);
        if(ll == tot && k != 0) {
            ll = k;
            lid = l;
            rid = m;
            rrid = r;
        }
        if(k > 0) r = m;
        else l = m + 1;
    }
    int ansi = l - 1;
    rr = ask(rid + 1, rrid);
    if(ll + rr == tot) {
        cerr << "A\n";
        int ansj = rid + 1;
        int ansk = rid + sqrt(2 * rr) + 1;
        cout << "! " << ansi << ' ' << ansj << ' ' << ansk << endl;
        return;
    }
    if(ll == (rid - ansi) * (rid - ansi + 1) / 2) {
        cerr << "B\n";
        int k = tot - ll - rr;
        k /= (rid - ansi + 1);
        int ansj = rid + k + 1;
        int ansk = rid + sqrt(2 * rr - (k * (k - 1))) + k + 1;
        cout << "! " << ansi << ' ' << ansj << ' ' << ansk << endl;
        return;
    }
    else {
        cerr << "C\n";
        int k = tot - ll - rr;
        cerr << k << '\n';
        k /= (int)(floor(sqrt(2 * rr)) + 1);
        cerr << sqrt(2 * rr) + 1 << '\n';
        int ansj = rid - k + 1;
        int ansk = rid + sqrt(2 * rr) + 1;
        cout << "! " << ansi << ' ' << ansj << ' ' << ansk << endl;
        return;
    }
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