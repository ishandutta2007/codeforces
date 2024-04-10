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
void solve(int TC) {
    string a, n;
    cin >> a >> n;
    int pt = n.length() - 1;
    string b = "";
    for(int i = a.length() - 1; i >= 0; i--) {
        if(pt == -1) {
            cout << "-1\n";
            return;
        }
        if(a[i] <= n[pt]) {
            b = (char)('0' + (n[pt] - a[i])) + b;
            pt--;
        }
        else {
            if(pt == 0 || n[pt - 1] != '1') {
                cout << "-1\n";
                return;
            }
            b = (char)('0' + (n[pt] - a[i]) + 10) + b;
            pt -= 2;
        }
    }
    if(pt != -1) {
        b = n.substr(0, pt + 1) + b;
    }
    while(b[0] == '0' && b.length() > 1) {
        b = b.substr(1, b.length() - 1);
    }
    cout << b << '\n';
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