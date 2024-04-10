#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int candy[1010];
int arr[303030];
int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> candy[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            arr[candy[i]+candy[j]]++;
        }
    }

    int mx = 0;
    for (int i=0; i<303030; i++) {
        mx = max(mx, arr[i]);
    }

    cout << mx;

}