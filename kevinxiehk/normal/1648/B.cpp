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
int ps[2000005];
void solve(int TC) {
    int n, c;
    cin >> n >> c;
    set<int> a;
    int t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        a.insert(t);
    }
    for(int i = 0; i <= c * 2; i++) ps[i] = 0;
    n = a.size();
    for(auto x: a) ps[x]++;
    for(int i = 1; i <= c * 2; i++) ps[i] += ps[i - 1];
    if(ps[1] == 0) {
        cout << "No\n";
        return;
    }
    for(auto i: a) {
        int sum = ps[i - 1];
        for(int j = 1; j <= c / i; j++) {
            if(ps[j] > ps[j - 1]) {
                sum += ps[i * j + i - 1] - ps[i * j - 1];
            }
        }
        if(sum != n) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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