#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    sort(v.begin(), v.begin() + k, [](auto p, auto q) {
        return p.second < q.second;
    });
    
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += v[i].first;
    v[k-1].second = n;

    cout << sum << '\n';
    int last = 0;
    for (int i = 0; i < k; i++) {
        cout << v[i].second - last << ' ';
        last = v[i].second;
    }
    cout << endl;
}