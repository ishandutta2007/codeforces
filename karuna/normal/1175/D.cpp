#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int arr[303030];
ll pfx[303030], asum;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<n; i++) {
        if (i==0) pfx[i] = (ll)arr[i];
        else pfx[i] = pfx[i-1]+arr[i];
    }

    asum = pfx[n-1]*k;
    pfx[n-1] = 1LL<<60;

    sort(pfx, pfx+n);

    for (int i=0; i<k-1; i++) {
        asum -= pfx[i];
    }

    cout << asum;
}