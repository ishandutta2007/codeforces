#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    int right = *max_element(a.begin(), a.end());
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n; i++) {
        while (a[i] < right) {
            right--;
            sum--;
        }
        right--;
        sum--;
    }
    if (right > 0)
        sum -= right;
    cout << sum << '\n';
}