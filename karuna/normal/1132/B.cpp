#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll arr[404040];
ll cp[404040];
int main() {
    int n;
    scanf("%d", &n);

    ll sum = 0;
    for (int i=0; i<n; i++) {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }

    sort(arr, arr+n);

    int m;
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%lld", &cp[i]);
        printf("%lld\n", sum-arr[n-cp[i]]);
    }


}