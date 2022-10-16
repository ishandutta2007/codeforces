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
struct sth {
    int val;
    //vector<int> way(10);
    vector<int> way = vector<int>(10);
    bool operator>(sth b) const {
        if(val == b.val) return way > b.way;
        return val > b.val;
    }
    bool operator<(sth b) const {
        if(val == b.val) return way < b.way;
        return val < b.val;
    }
};
void solve(int TC) {
    int n;
    cin >> n;
    vector<int> stuff[n + 5];
    for(int i = 0; i < n; i++) {
        int t, tt;
        cin >> t;
        stuff[i].pb(INT_MIN);
        while(t--) {
            cin >> tt;
            stuff[i].pb(tt);
        }
    }
    int m;
    cin >> m;
    int mm = m;
    map<vector<int>, bool> cant;
    vector<int> aaa(10);
    while(m--) {
        for(int i = 0; i < n; i++) cin >> aaa[i];
        cant[aaa] = true;
    }
    set<sth> exhaust;
    sth idk;
    idk.val = 0;
    for(int i = 0; i < n; i++) {
        idk.way[i] = stuff[i].size() - 1;
        idk.val += stuff[i][stuff[i].size() - 1];
    }
    exhaust.insert(idk);
    sth now;
    while(1) {
        while (exhaust.size() > mm + 1) exhaust.erase(exhaust.begin());//return;
        //now = *(exhaust.rbegin());return;
        auto it = exhaust.end();
        it--;
        now = *it;
        //cout << now.val << '\n';
        exhaust.erase(it);
       // exhaust.erase(exhaust.end());
        if(!cant[now.way]) {
            for(int i = 0; i < n; i++) cout << now.way[i] << ' ';
            //for(auto x: now.way) if(x) cout << x << ' ';
            cout << '\n';
            return;
        }
        for(int i = 0; i < n; i++) {
            if(now.way[i] == 1) continue;
            now.val -= stuff[i][now.way[i]] - stuff[i][now.way[i] - 1];
            now.way[i]--;
            exhaust.insert(now);
            now.way[i]++;
            now.val += stuff[i][now.way[i]] - stuff[i][now.way[i] - 1];
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}