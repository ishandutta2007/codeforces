/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        string s; cin >> s;
        vector<int> acc;
        s.pb('?');
        char sax = s[0];
        x = 0;
        for(char c : s){
            if(c == sax) ++x;
            else{
                acc.pb(x); x = 1;
            }
            sax = c;
        }
        bool f = 1;
        if(s[0] == 'B') f = 0;
        if(acc.size() & 1) f = 0;
        int rem = 0;
        for(int i = 1; i < acc.size(); i += 2){
            rem += acc[i - 1];
            rem -= acc[i];
            if(rem < 0) f = 0;
        }
        if(!f) cout << "NO\n";
        else cout << "YES\n";
    }
}