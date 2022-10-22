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
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int ans = oo;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> prm;

bool isprime[maxN * 5];
set<int> issolved;

void solving(int num){
    if(issolved.find(num) != issolved.end()) return;
    issolved.insert(num);
    // cout << num << endl;
    int res = 0;
    for1(i, 1, n){
        x = a[i] % num;
        if(x == a[i]) res += (num - x);
        else res += min(x, num - x);
    }
    ans = min(ans, res);
}

void solve(int num){
    if(num == 0) return;
    for(int child : prm){
        if(!(num % child)){
            solving(child);
            while(!(num % child)) num /= child;
        }
    }
    if(num != 1) solving(num);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
    }
    memset(isprime, 1, sizeof(isprime));
    for1(i, 2, maxN * 5 - 1){
        if(isprime[i]){
            prm.pb(i);
            for(int j = i * 2; j < maxN * 5; j += i){
                isprime[j] = 0;
            }
        }
    }
    for1(stfucus, 1, 30){
        int id = rng() % n;
        id = a[id + 1];
        solve(id);
        solve(id - 1);
        solve(id + 1);
    }
    cout << ans << endl;
}