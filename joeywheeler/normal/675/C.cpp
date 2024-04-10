#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
long long v[100005];
map<long long, int> m;

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", v+i);
    FO(i,1,n) v[i] += v[i-1];
    int res = 0;
    FO(i,0,n) res = max(res,++m[v[i]]);
    printf("%d\n", n-res);
}