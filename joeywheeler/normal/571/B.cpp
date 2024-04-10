#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
int v0, v1, n0, n1;
vector<int> clen;

int n, k;
vector<ll> a;

map<int,ll> cache[300005];

ll go(int i, int j, int k) {
    if (i == n) return 0;
    if (cache[i].count(j)) return cache[i][j];
    ll res = 1ll<<62;
    // use a v0
    if (j) {
        res = min(res, go(i+v0,j-1,k) + a[i+v0-1]-a[i]);
    }
    if (k) {
        res = min(res, go(i+v1,j,k-1) + a[i+v1-1]-a[i]);
    }
    return cache[i][j] = res;
}

int main() {
    scanf("%d %d", &n, &k);
    FO(i,0,k) {
        int l = 0;
        for (int j = i; j < n; j += k) l++;
        clen.push_back(l);
        if (v0 == 0 || v0 == l) v0 = l;
        else v1 = l;
        if (l == v0) n0++;
        else n1++;
    }
    a.resize(n);
    FO(i,0,n) scanf("%lld", &a[i]);
    sort(a.begin(),a.end());
    printf("%lld\n", go(0,n0,n1));
}