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
const int mod = 998244353;
vector<int> conn[1005];
int n, m;
bool pass[1005][1005];
int cnt[1005];
bool cntd[1005];
int in[1005];
queue<int> start;
int lef = 0;
void solve(int TC) {
    cin >> n >> m;
    lef = n;
    for(int i = 0; i <= n; i++) {
        conn[i].clear();
        in[i] = 0;
        for(int j = 0; j <= n + 2; j++) pass[i][j] = false;
    }   
    int a, b;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> cnt[i];
        sum += cnt[i];
        cntd[i] = false;
        
        for(int j = 0; j <= min(n, cnt[i] - 1); j++) pass[i][j] = true;
        if(cnt[i] >= mod) {
            cnt[i] %= mod;
            cntd[i] = true;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        in[b]++;
        conn[a].pb(b);
    }
    if(sum == 0) {
        cout << "0\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) start.push(i);
    }
    while(!start.empty()) {
        int x = start.front();
        start.pop();
        if(lef == 1) {
            if(cntd[x]) cnt[x] += mod;
            for(int i = 0; i <= n; i++) {
                if(pass[x][i]) {
                    cnt[x]--;
                    if(cnt[x] == 0) {   
                        cout << i + 1 << '\n';
                        return;
                    }
                }
            }
            cout << (cnt[x] + n + 1) % mod << '\n';
            return;
        }
        else {
            for(auto xx: conn[x]) {
                in[xx]--;
                if(in[xx] == 0) start.push(xx);
                cntd[xx] |= cntd[x];
                if(cnt[xx] + cnt[x] >= mod) cntd[xx] = true;
                cnt[xx] = (cnt[xx] + cnt[x]) % mod;
                int tc = 0;
                for(int i = 0; i <= n; i++) {    
                    if(tc > 0 && !pass[xx][i]) {
                        tc--;
                        pass[xx][i] = true;
                    }
                    if(pass[x][i]) tc++;
                }
            }
            lef--;
        }
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