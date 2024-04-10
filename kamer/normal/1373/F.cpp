#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <numeric>
using namespace std;
typedef long long ll;

bool solveWithin(int l, int r, vector<ll>& a, vector<ll>& b) {
    if (r <= l + 1) {
        return true;
    }

    int mid = (r + l) / 2;
    if (!solveWithin(l, mid, a, b)) return false;
    if (!solveWithin(mid, r, a, b)) return false;

    ll minLeft = 0;
    ll sumLeft = 0;
    for (int i = mid - 1; i >= l; i--) {
        sumLeft = sumLeft + b[i - 1] - a[i];
        minLeft = min(minLeft, sumLeft);
    }

    ll minRight = 0;
    ll sumRight = 0;
    for (int i = mid; i < r; i++) {
        sumRight = sumRight + b[i] - a[i];
        minRight = min(minRight, sumRight);
    }

    if ((b[mid - 1] + minLeft + minRight) < 0) {
        return false;
    }

    return true;
}

void solve(int n, vector<ll>& a, vector<ll>& b) {
    ll sumA = accumulate(a.begin(), a.end(), (ll)0);
    ll sumB = accumulate(b.begin(), b.end(), (ll)0);
    if (sumA > sumB) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > (b[(i - 1 + n) % n] + b[i])) {
            cout << "NO\n";
            return;
        }
    }

    vector<ll> rightSums(n - 1, 0);
    for (int i = 1; i < n - 1; i++) {
        rightSums[i] = rightSums[i - 1] + b[i - 1] - a[i - 1];
    }
    vector<ll> leftSums(n - 1, 0);
    for (int i = 1; i < n - 1; i++) {
        leftSums[i] = leftSums[i - 1] + b[n - i - 1] - a[n - i];
    }
    vector<ll> minLeftSums(n - 1, 0);
    for (int i = 1; i < n - 1; i++) {
        minLeftSums[i] = min(minLeftSums[i - 1], leftSums[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        if ((b[n - 1] + rightSums[i] + minLeftSums[n - 2 - i]) < 0) {
            cout << "NO\n";
            return;
        }
    }

    if (solveWithin(1, n - 1, a, b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        solve(n, a, b);
    }
}