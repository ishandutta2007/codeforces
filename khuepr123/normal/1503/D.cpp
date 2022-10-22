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
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
bool trg[maxN];
int x, y, z, k;
 
void prt(int vale){
    cout << vale << endl;
    exit(0);
}
 
int cn[2];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> x >> y; bool bk = 0;
        if(x < y){
            swap(x, y); bk = 1;
        }
        x = n * 2 + 1 - x;
        if(x > n || y > n) prt(-1);
        a[x] = y;
        trg[x] = bk;
    }
    int l = 1;
    int mx = 0;
    int ans = 0;
    for1(i, 1, n){
        mx = max(mx, a[i]);
        if(mx == i){
            int val = l;
            memset(cn, 0, sizeof(cn));
            vector<int> flx;
            set<int> st;
            for1(j, l, i){
                while(st.find(val) != st.end()) ++val;
                if(a[j] == val){
                    cn[0 ^ trg[j]]++;
                }
                else{
                    cn[1 ^ trg[j]]++; 
                    flx.pb(a[j]);
                }
                st.insert(a[j]);
            }
            for1(i, 1, (int)flx.size() - 1){
                if(flx[i] < flx[i - 1]) prt(-1);
            }
            ans += min(cn[0], cn[1]);
            l = i + 1;
        }
    }
    prt(ans);
}