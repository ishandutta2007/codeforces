
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option
 
#include<bits/stdc++.h>
using namespace std;
 
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
const int maxN = 400005;
const ll oo = 1e18 + 7;
const int god = maxN - 1;
int n, a[maxN];
int x, y, z, k;
 
int l[maxN];
int r[maxN];
int val[maxN];
int pin[maxN];
int cnt = 2;
 
int b, s;
priority_queue<ii, vector<ii>, greater<ii>> pq;

inline void conn(int v1, int v2){
    l[v2] = v1;
    r[v1] = v2;
}
 
void reset(){
    b = 0;
    s = 0;
    ++cnt;
    conn(0, cnt);
    conn(cnt, god);
    val[cnt] = 0; pin[cnt] = 0;
    while(!pq.empty()) pq.pop();
}
 
inline void embed(int p1, int p2){
    if(p2 == god || p1 == 0) return;
    int v1 = val[p1] - val[p2];
    int v2 = pin[p2] - pin[p1];
    pq.push(ii((v1 + v2 - 1) / v2, p2));
}

set<int> rmd;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    reset();
    while(o--){
        cin >> z >> x;
        if(z == 1){
            reset();
            n += x;
        }
        else if(z == 2){
            y = l[god];
            ++cnt;
            val[cnt] = 0 - s - (n * b);
            pin[cnt] = n;
            conn(y, cnt);
            conn(cnt, god);
            n += x;
            embed(y, cnt);
        }
        else{
            cin >> y;
            b += y;
            s += x;
        }
        while(!pq.empty() && (pq.top()).fi <= b){
            x = (pq.top()).se; pq.pop();
            if(rmd.find(x) != rmd.end()) continue;
            conn(l[x], r[x]);
            embed(l[x], r[x]);
            rmd.insert(x);
        }
        x = l[god];
        cout << pin[x] + 1 << " " << val[x] + b * pin[x] + s << endl;
    }
}