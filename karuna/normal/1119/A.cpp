#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
ll arr[302020];

int main() {
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxi = 0;
    for (int i=n; i>0; i--) {
        if (arr[i] != arr[1]) {
            maxi = i-1;
            break;
        }
    }

    for (int i=1; i<=n; i++) {
        if (arr[i] != arr[n]) {
            maxi = max(maxi, n-i);
            break;
        }
    }

    printf("%d", maxi);

}