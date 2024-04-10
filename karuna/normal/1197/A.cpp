#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, n;
int arr[101010];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];

        sort(arr, arr+n);

        cout << min(n-2, arr[n-2]-1) << '\n';
    }
}