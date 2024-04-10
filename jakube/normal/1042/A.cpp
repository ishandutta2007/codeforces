#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;

    int ma = *max_element(v.begin(), v.end()) + m;
    while (m --> 0) {
        int mi = *min_element(v.begin(), v.end());
        ++*find(v.begin(), v.end(), mi);
    }
    int mi = *max_element(v.begin(), v.end());
    cout << mi << " " << ma << '\n';
}