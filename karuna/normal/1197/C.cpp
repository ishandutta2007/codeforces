#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k, ans;
int arr[303030], brr[303030];
int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];

    ans = arr[n-1]-arr[0];

    for (int i=0; i<n-1; i++) {
        brr[i] = arr[i+1]-arr[i];
    }

    sort(brr, brr+n-1);

    for (int i=n-2; i>n-k-1; i--) {
        ans -= brr[i];
    }

    cout << ans;
}