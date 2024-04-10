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
void solve(int TC) {
    int n;
    cin >> n;
    map<int, int> freq;
    n--;
    int t;
    freq[0]++;
    while(n--) {
        cin >> t;
        freq[t]++;
    }
    vector<int> cn;
    for(auto x: freq) cn.pb(x.se);
    sort(cn.begin(), cn.end());
    reverse(cn.begin(), cn.end());
    int an = cn.size();
    priority_queue<int> lef;
    for(int i = 0; i < an; i++) {
        if(cn[i] - (an - i) > 0) {
            lef.push(cn[i] - (an - i));
        }
    }
    int add = 0;
    while(!lef.empty() && lef.top() > add) {
        int x = lef.top();
        lef.pop();
        x--;
        add++;
        lef.push(x);
    }
    cout << an + add << '\n';
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