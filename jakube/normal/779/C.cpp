#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<pair<int, int>> savings;
    for (int i = 0; i < n; i++) {
        savings.push_back({a[i] - b[i], i});
    }
    sort(savings.begin(), savings.end());

    long long result = accumulate(b.begin(), b.end(), 0LL);
    
    for (int i = 0; i < k || (i < n && savings[i].first < 0); i++)
        result += savings[i].first;

    cout << result << endl;

    return 0;
}