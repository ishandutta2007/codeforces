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
int x, y, z, k;

int sum = 0;
int numwon;
bool won;

void back(int pos){
    if(pos > n){
        if(sum == 0) ++numwon;
        return;
    }
    sum -= a[pos] * 2;
    for1(wat, 0, 2){
        sum += a[pos];
        back(pos + 1);
    }
    sum -= a[pos];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            cin >> a[i];
        }
        won = 0;
        numwon = 0;
        for1(i, 1, n){
            if(a[i] == 0){
                won = 1;
            }
        }
        back(1);
        if(numwon >= 2) won = 1;
        if(won) cout << "YES\n";
        else cout << "NO\n";
    }
}