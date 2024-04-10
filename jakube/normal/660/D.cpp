#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx].first >> v[idx].second;


    map<pair<int, int>, int> m;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            pair<int, int> vec = { v[j].first - v[i].first, v[j].second - v[i].second };
            pair<int, int> rev_vec = { -v[j].first + v[i].first, -v[j].second + v[i].second };

            result += m[vec];

            m[vec]++;
            m[rev_vec]++;
        }
    }

    cout << result / 2 << endl;
}