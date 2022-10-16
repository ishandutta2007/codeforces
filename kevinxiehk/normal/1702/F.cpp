#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
// #define int long long
#define inf 1e9
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
map<int, int> seg;
map<int, bool> vi;
priority_queue<int> pushup;
void solve() {
    
    seg.clear();
    vi.clear();
    while(!pushup.empty()) pushup.pop();
    int n;
    cin >> n;
    int t;
    for(int i = 0; i < n; i++) {
        cin >> t;
        seg[t]--;
        pushup.push(t);
    }
    for(int i = 0; i < n; i++) {
        cin >> t;
        seg[t]++;
        pushup.push(t);
    }
    vi[0] = true;
    while(!pushup.empty()) {
        int now = pushup.top();
        pushup.pop();
        if(vi[now]) continue;
        // cout << now << ' ' << seg[now].fi << '\n';
        vi[now] = true;
        if(seg[now] < 0 && now % 2 == 1) {
            cout << "NO\n";
            return;
        }
        seg[now / 2] += seg[now];
        // seg[now / 2].se += seg[now].se + abs(seg[now].fi);
        // cerr << now << ' ' << seg[now].fi << ' ' << seg[now].se << '\n';;
        pushup.push(now / 2);
    }
    cout << "YES" << '\n';
    return;
}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}