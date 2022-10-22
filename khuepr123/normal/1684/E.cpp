#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int> choi;
int acc = 0;

void rem(){
    pq.push(choi.top());
    acc -= choi.top(); choi.pop();
}

void sal(int x){
    acc += x; choi.push(x);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n >> k;
        map<int, int> mp;
        for1(i, 1, n){
            cin >> x; ++mp[x];
        }
        acc = 0;
        while(!pq.empty()) pq.pop();
        while(!choi.empty()) choi.pop();
        pq.push(oo);
        choi.push(-oo);
        while(!mp.empty()){
            auto itr = mp.rbegin();
            if(itr->fi >= n){
                pq.push(itr->se);
                mp.erase(itr->fi);
            }
            else break;
        }
        int ans = oo;
        for2(i, n, 0){
            if(mp.find(i) != mp.end()){
                pq.push(mp[i]);
                mp.erase(i);
            }
            int best = i - mp.size();
            // cout << mp.size() << endl;
            while(choi.top() > pq.top()){
                sal(pq.top()); pq.pop();
            }
            while(acc > k) rem();
            while(acc + pq.top() <= k){
                sal(pq.top()); pq.pop();
            }
            if(best <= k) ans = min(ans, (int)pq.size() - 1);
            // cout << (int)pq.size() - 1 << " " << best << endl;
            // cout << mp.size() << endl;
        }
        cout << ans << endl;
    }
}