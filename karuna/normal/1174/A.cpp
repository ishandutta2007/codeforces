#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int arr[2020202];
ll a, b;
int main() {
    scanf("%d", &n);
    for (int i=0; i<2*n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+2*n);

    for (int i=0; i<n; i++) {
        a += (ll)arr[i];
        b += (ll)arr[n+i];
    }

    if (a==b) printf("-1");
    else {
        for (int i=0; i<2*n; i++) {
            printf("%d ", arr[i]);
        }
    }
}