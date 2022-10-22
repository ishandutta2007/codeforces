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

int prt(int ttt, int iii, int jjj, int kkk){
    cout << ttt << " ";
    cout << iii << " ";
    cout << jjj << " ";
    cout << kkk << " ";
    cout << endl;
    int dumbass; cin >> dumbass; return dumbass;
}

int nx[maxN];

void execute(int nd1, int nd2, vector<int> vc){
    if(vc.size() == 0){
        nx[nd1] = nd2; return;
    }
    vector<ii> bucket;
    for(int child : vc){
        x = prt(1, nd1, nd2, child);
        bucket.pb(ii(x, child));
    }
    sort(bucket.begin(), bucket.end());
    ii mx = bucket.back();
    vc.clear();
    for(ii child : bucket){
        if(child == mx) break;
        int cc = child.se;
        x = prt(2, nd2, cc, mx.se);
        if(x == 1){
            nx[cc] = nd2;
            nd2 = cc;
        }
        else{
            nx[nd1] = cc;
            nd1 = cc;
        }
    }
    nx[nd1] = mx.se;
    nx[mx.se] = nd2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> dumb1, dumb2;
    for1(i, 3, n){
        x = prt(2, 1, 2, i);
        if(x == 1) dumb1.pb(i);
        else dumb2.pb(i);
    }
    execute(1, 2, dumb1);
    execute(2, 1, dumb2);
    int node = nx[1];
    cout << 0 << " " << 1 << " ";
    vector<int> vc;
    for1(i, 1, n - 1){
        vc.pb(node);
        node = nx[node];
    }
    reverse(vc.begin(), vc.end());
    for(int child : vc) cout << child << " ";
    cout << endl;
    return 0;
}