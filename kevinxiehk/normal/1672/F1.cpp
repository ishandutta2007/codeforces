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
    int arr[n + 5];
    queue<int> pls[n + 5];
    int nxt[n + 5];
    for(int i = 0; i < n; i++) nxt[i] = (i + 1) % n;
    pair<int, int> ar[n + 5];
    for(int i = 0; i <= n; i++) ar[i] = mp(0, i);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        pls[arr[i]].push(i);
        ar[arr[i]].fi++;
    }
    // sort(ar, ar + n + 1);
    // reverse(ar, ar + n + 1);
    // reverse(ar.begin(), ar.end());
    queue<int> proc;
    for(int i = 1; i <= n; i++) if(!pls[i].empty()) proc.push(i);
    pair<int, int> an[n + 5];
    int pt = 0;
    int now;
    for(int i = 0; i < n; i++) {
        now = proc.front();
        proc.pop();
        an[i] = mp(now, pls[now].front());
        pls[now].pop();
        if(!pls[now].empty()) proc.push(now);
    }
    for(int i = 0; i < n; i++) {
        arr[an[(i + 1) % n].se] = an[i].fi;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
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