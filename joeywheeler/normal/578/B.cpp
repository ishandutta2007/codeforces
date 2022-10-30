#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n; int k; ll x;

ll fo[200005], bo[200005], v[200005];

int main() {
    scanf("%d%d%lld", &n, &k, &x);
    FO(i,0,n) {
        scanf("%lld", &v[i]);
        if (i != 0) fo[i] = fo[i-1] | v[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        bo[i] = bo[i+1] | v[i+1];
    }
    ll res = 0;
    FO(i,0,n) {
        ll nv = v[i];
        FO(z,0,k) nv *= x;
        res = max(res, nv | fo[i] | bo[i]);
    }
    printf("%lld\n", res);
}