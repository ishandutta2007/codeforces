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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int cnt[maxN];
 
set<int> st;
set<int> st2;
int layer = 0;
 
int qr = 0;
 
void fact(int nd){
    ++qr;
    if(qr == 61) assert(0 > 1);
    // cout << 1 << endl;
    z = nd;
    int cntt = 0;
    for1(i, 1, n){
        cout << "? " << x << " " << i << " " << z << endl;
        string s; cin >> s;
        if(s[0] == 'Y' && st2.find(i) != st2.end()){
            ++cntt;
        }
    }
    if(cntt == layer){
        cout << "! " << nd << endl;
        exit(0);
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    x = 1;
    y = n;
    while(x <= y){
        y -= x;
        layer++;
        x *= k;
    }
    layer = layer * 2 - 1;
    memset(cnt, 0, sizeof(cnt));
    vector<int> dumb;
    while(1){
        ++qr;
        if(qr == 61) exit(0);
        while(1){
            x = rng() % n;
            y = rng() % n;
            if(x != y) break;
        }
        ++x; ++y;
        dumb.clear();
        for1(i, 1, n){
            cout << "? " << x << " " << i << " " << y << endl;
            string s; cin >> s;
            if(s[0] == 'Y') dumb.pb(i);
        }
        if(dumb.size() == layer) break;
    }
    for(int child : dumb) st.insert(child);
    for(int child : dumb) st2.insert(child);
    layer++; layer /= 2;
    for(int child : st2) fact(child);
}