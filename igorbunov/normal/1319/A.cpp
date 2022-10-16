#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    int a = 0;
    int b = 0;

    for (int i = 0; i < n; i++) {
        if (arr1[i] == 1 && arr2[i] == 0) {
            a++;
        }
        if (arr1[i] == 0 && arr2[i] == 1) {
            b++;
        }
    }

    if (a == 0) {
        cout << -1;
        return 0;
    }

    cout << b / a + 1;
    return 0;
}