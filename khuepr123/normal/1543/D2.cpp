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

vector<int> conv(int val){
    vector<int> res;
    while(val){
        res.pb(val % k);
        val /= k;
    }
    if(res.empty()) res.pb(0);
    return res;
}

int solve_add(vector<int> v1, vector<int> v2){
    int cf = 1;
    int res = 0;
    while(v2.size() < v1.size()) v2.pb(0);
    while(v1.size() < v2.size()) v1.pb(0);
    for1(i, 0, v2.size() - 1){
        int num = ((v1[i] + v2[i]) % k + k) % k;
        res += num * cf;
        cf *= k;
    }
    return res;
}

int add(int v1, int v2){
    return solve_add(conv(v1), conv(v2));
}

int sub(int v1, int v2){
    vector<int> b1 = conv(v1);
    vector<int> b2 = conv(v2);
    for(auto &cc : b2){
        if(cc != 0) cc = k - cc;
    }
    return solve_add(b1, b2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        int val = 0;
        bool ad = 1;
        for1(i, 0, n - 1){
            if(ad) x = add(i, val);
            else x = sub(val, i);
            cout << x << endl; cin >> y; if(y) break;
            val = sub(x, val);
            ad = !ad;
        }
    }
}