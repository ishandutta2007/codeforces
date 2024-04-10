#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }
    ll res = 0;
    ll currSum = 0;
    for (int i = 0; i < n - 1; i += 2) currSum += a[i];
    res = currSum + max(a[n - 2], a[n - 1]);
    ll currIndex = 2;
    while (currIndex != 0) {
        currSum = currSum - a[(currIndex + n - 2) % n] + a[(currIndex + n - 3) % n];
        res = max(res, currSum + a[(currIndex + n - 2) % n]);
        res = max(res, currSum + a[(currIndex + n - 1) % n]);
        currIndex = (currIndex + 2) % n;
    }
    cout << res << "\n";

}