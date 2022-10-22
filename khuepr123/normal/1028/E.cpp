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
int b[maxN];
map<int, int> mp;
int sum = 0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
        sum += a[i];
        mp[a[i]]++;
    }
    bool fk = 1;
    if(sum == 0){
        cout << "YES\n";
        for1(i, 1, n){
            cout << "1337 ";
        }
        return 0;
    }
    // if(sum % 2 == 0) if(mp[sum / 2] == 2){
    //     cout << "NO\n"; return 0;
    // }
    for(ii child : mp){
        if(child.se == n){
            cout << "NO\n"; return 0;
        }
    }
    ii best = {0, 0};
    for1(i, 1, n){
        int pre = (i - 1);
        if(pre == 0) pre = n;
        if(a[i] >= best.fi && a[i] != a[pre]){
            best.fi = a[i];
            best.se = i;
        }
    }
    int cur = best.se;
    b[cur] = a[cur];
    for1(i, 1, n - 1){
        int pre = (cur - 1);
        if(pre == 0) pre = n;
        // cout << cur << " " << pre << endl;
        b[pre] = b[cur] + a[pre];
        if(fk) b[pre] += b[cur];
        fk = 0;
        cur = pre;
    }
    cout << "YES\n";
    for1(i, 1, n){
        cout << b[i] << " ";
    }
}