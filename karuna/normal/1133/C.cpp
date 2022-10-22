#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll arr[202020];
int main() {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);

    int ub;
    int maxi = 0;
    for (int i=0; i<n; i++) {
        ub = upper_bound(arr, arr+n, arr[i]+5) - (arr+i);
        maxi = max(maxi, ub);
    }

    printf("%d", maxi);
}