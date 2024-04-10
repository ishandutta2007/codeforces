#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n, k0, k1;
int a[1005], b[1005];

int main() {
    scanf("%d %d %d", &n, &k0, &k1);
    fo(i,0,n) scanf("%d", a+i);
    fo(i,0,n) scanf("%d", b+i);
    fo(i,0,n) a[i] = abs(a[i]-b[i]);
    fo(z,0,k0+k1) {
        sort(a,a+n);
        a[n-1] = abs(a[n-1]-1);
    }
    ll res = 0;
    fo(i,0,n) {
        res += a[i] * 1ll * a[i];
    }
    printf("%lld\n", res);
}