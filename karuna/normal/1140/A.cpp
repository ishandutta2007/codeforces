#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[10101];
int main() {
    int n;
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    int day = 0;
    int maxi;
    for (int i=1; i<=n; i++) {
        day++;
        maxi = arr[i];
        while (maxi > i) {
            i++;
            maxi = max(maxi, arr[i]);
        }
    }

    printf("%d", day);
}