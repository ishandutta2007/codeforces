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
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, a[maxN], o;
int x, y, z, k;

int b[maxN];
map<int, int> mp;
struct query{
    int type, x, y;
} qr[maxN];

int pre[maxN * 4];
int num[maxN * 4];
int dis[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];

inline void combi(int node, int v1, int v2){
    dis[node] = pre[v2] * num[v1] - pre[v1] * num[v2] + dis[v1] + dis[v2];
    pre[node] = pre[v1] + pre[v2];
    num[node] = num[v1] + num[v2];

}

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    if(left == right) return;
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

int inc, ison;

void upd(int node, int pin){
    if(l[node] == r[node]){
        pre[node] += inc;
        num[node] += ison;
        return;
    }
    if(r[node * 2] >= pin) upd(node * 2, pin);
    else upd(node * 2 + 1, pin);
    combi(node, node * 2, node * 2 + 1);
}

void take(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        combi(0, 0, node);
        // cout << dis[node] << " " << num[node] << " " << pre[node] << endl;
        // cout << dis[0] << " " << num[0] << " " << pre[0] << endl;
        return;
    }
    int mid = r[node * 2];
    take(node * 2, left, min(mid, right));
    take(node * 2 + 1, max(left, mid + 1), right);
}

void show(){
    for1(i, 1, 7){
        cout << l[i] << " " << r[i] << " "
         << dis[i] << " " << pre[i] << " " << num[i] << endl;
    }
    cout << endl;
}

signed main(){
    memset(pre, 0, sizeof(pre));
    memset(dis, 0, sizeof(pre));
    memset(num, 0, sizeof(pre));
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    build(1, 1, maxN - 1);
    for1(i, 1, n){
        cin >> a[i];
        b[i] = a[i];
        mp[a[i]] = 0;
    }
    cin >> o;
    for1(i, 1, o){
        cin >> qr[i].type >> qr[i].x >> qr[i].y;
        if(qr[i].type == 1){
            b[qr[i].x] += qr[i].y;
            mp[b[qr[i].x]] = 0;
        }
    }
    x = 0;
    mp[oo] = 1;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        itr->se = ++x;
    }
    for1(i, 1, n){
        inc = a[i]; ison = 1;
        upd(1, mp[a[i]]);
    }
    for1(i, 1, o){
        x = qr[i].x;
        y = qr[i].y;
        if(qr[i].type == 1){
            inc = -a[x]; ison = -1;
            upd(1, mp[a[x]]);
            a[x] += y;
            inc = a[x]; ison = 1;
            upd(1, mp[a[x]]);
        }
        else{
            x = mp.lower_bound(x)->se;
            y = (--mp.upper_bound(y))->se;
            pre[0] = 0;
            num[0] = 0;
            dis[0] = 0;
            take(1, x, y);
            cout << dis[0] << endl;
        }
    }
}