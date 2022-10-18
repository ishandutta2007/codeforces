#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (auto& x : ab)
        cin >> x.first >> x.second;
    
    sort(ab.begin(), ab.end(), [](auto p, auto q) {
        return p.first - p.second > q.first - q.second;
    });

    long long total = 0;
    int left = 0, right = n-1;
    for (auto [a, b] : ab) {
        total += (long long)a * left + (long long)b * right;
        left++;
        right--;
    }
    cout << total << '\n';
}