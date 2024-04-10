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
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.se == b.se) return a.fi < b.fi;
    return a.se < b.se;
}
int process(vector<int> arr){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int rt = n * (n - 1) / 2;
    int minus = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) {
            rt -= minus;
            minus++;
        }
        else minus = 1;
    }
    return rt;
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int arrx[n + 5];
    int arry[m + 5];
    pair<int, int> ppl[k + 5];
    for(int i = 0; i < n; i++) {
        cin >> arrx[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> arry[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> ppl[i].fi >> ppl[i].se;
    }
    int ans = 0, tcnt = 0;
    unordered_map<int, int> cnt;
    sort(ppl, ppl + k);
    int pt = 0, ls = -1;
    vector<int> tmp;
    for(int i = 0; i < k; i++) {
        while(arrx[pt] < ppl[i].fi) {
            pt++;
        }
        if(pt != ls) {
            ans += process(tmp);
            tmp.clear();
        }
        ls = pt;
        if(arrx[pt] == ppl[i].fi) continue;
        tmp.pb(ppl[i].se);
    }
    ans += process(tmp);
    sort(ppl, ppl + k, cmp);
    pt = 0, ls = -1;
    tcnt = 0;
    tmp.clear();
    for(int i = 0; i < k; i++) {
        while(arry[pt] < ppl[i].se) {
            pt++;
        }
        if(pt != ls) {
            ans += process(tmp);
            tmp.clear();
        }
        ls = pt;
        if(arry[pt] == ppl[i].se) continue;
        tmp.pb(ppl[i].fi);
    }
    ans += process(tmp);
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}