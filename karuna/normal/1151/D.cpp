#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pll;

ll n;
pll arr[101010];
bool cmp(pll &a, pll &b) {
    return (a.va-a.vb)-(b.va-b.vb) > 0;
}
int main() {
    scanf("%lld", &n);
    for (ll i=0; i<n; i++) {
        scanf("%lld%lld", &arr[i].va, &arr[i].vb);
    }

    sort(arr, arr+n, cmp);
    ll ans = 0;
    for (ll i=0; i<n; i++) {
        ans += (ll) arr[i].va*i+arr[i].vb*(n-i-1);
    }
    printf("%lld", ans);
}