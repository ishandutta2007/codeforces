#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<limits>
#include<cmath>
#include<map>
#include <set>
using namespace std;
#define ll long long
const int N = 2e5 + 10;

int n, m;
const ll mod = 1e9 + 7;
ll qpow(ll a, ll  b) {
    ll ans = 1;
    while (b) {
        if(b&1)
            ans = (ans * a)%mod;
        a = (a * a)%mod;
        b /= 2;
    }
    return ans;
}
int main () {
 int t;
 cin >> t;
    while (t--) {
        cin >> n >> m;
        ll res = 0;
        for(int i = 1; i <= m; i++) {
            int lo, hi, v;
            cin >> lo >> hi >> v;
            res |= v;
        }
        cout << ((res%mod) * qpow(2, n - 1)%mod)%mod << "\n";

    }
}