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
const int maxN = 3000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

bool isprime[maxN];
int assoc[maxN];
int cnt = 0;

multiset<int> mt[2];

void rem(multiset<int> &db, int val){
    db.erase(db.find(val));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(isprime, 1, sizeof(isprime));
    for1(i, 1, maxN - 1) assoc[i] = i;
    for1(i, 2, maxN - 1){
        if(isprime[i]){
            assoc[i] = ++cnt;
            for(int j = i * 2; j < maxN; j+=i){
                if(assoc[j] == j) assoc[j] /= i;
                isprime[j] = 0;
            }
        }
    }
    cin >> n;
    for1(i, 1, n * 2){
        cin >> x; mt[isprime[x]].insert(x);
    }
    while(mt[0].size()){
        x = *(--mt[0].end());
        rem(mt[0], x);
        y = assoc[x];
        rem(mt[isprime[y]], y);
        cout << x << " ";
    }
    while(mt[1].size()){
        x = *(--mt[1].end());
        rem(mt[1], x);
        rem(mt[1], assoc[x]);
        cout << assoc[x] << " ";
    }
}