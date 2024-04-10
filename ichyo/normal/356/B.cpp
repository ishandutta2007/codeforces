#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;
ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int main(){
    const int MAXL = 1000000 + 2;
    ll n, m;
    while(cin >> n >> m){
        string s, t;
        cin >> s >> t;
        ll l1 = s.size();
        ll l2 = t.size();
        ll g = gcd(l1, l2);
        ll lcm = l1 / g * l2;
        ll times = n * l1 / lcm;
        static int cnt[MAXL][26] = {};
        for(int i = 0; i < g; i++)
            for(int j = 0; j < 26; j++)
                cnt[i][j] = 0;
        for(int i = 0; i < l2; i++){
            cnt[i % g][t[i] - 'a']++;
        }
        ll ans = n * l1;
        for(int i = 0; i < l1; i++){
            ans -= times * cnt[i % g][s[i] - 'a'];
        }
        cout << ans << endl;
    }
    return 0;
}