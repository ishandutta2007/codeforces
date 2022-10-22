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
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, m;
int x, y, z, k;

int cou[maxN];
int pre[maxN];
int preres[maxN];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        int ans = 0;
        string s; cin >> s;
        for1(i, 0, m * n - 1){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        for1(i, 0, m - 1) cou[i] = 0;
        x = 0;
        for1(i, 1, m * n) preres[i] = 0;
        for1(i, 0, m * n - 1){
            int j = i % m;
            if(cou[j] == 0){
                if(s[i] == '0'){
                    ++x;
                    cou[j] = 1;
                }
            }
            preres[i + 1] += x;
        }
        // for1(i, 1, m * n) cout << preres[i] << " ";
        // cout << endl;
        pre[0] = 0;
        for1(i, 1, m * n){
            pre[i] = pre[i - 1];
            if(s[i - 1] == '0') ++pre[i];
            //  << pre[i] << " ";
        }
        // cout << endl;
        for1(i, 1, m){
            int pval = 0;
            int res = 0;
            for1(j, 0, n - 1){
                int id = j * m + i;
                if(pre[id] - pval) ++res;
                preres[id] += res;
                // if(i == 1) cout << pre[id] << " " << pval << endl;
                pval = pre[id];
            }
        }
        for1(i, 1, m * n) cout << preres[i] << " ";
        cout << endl;
    }
}