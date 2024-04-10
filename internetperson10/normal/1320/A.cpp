#include <bits/stdc++.h>

using namespace std;

map<int, long long int> cities;
vector<int> b;

int main() {
    int n;
    long long int ans = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        cities[k-i] += k;
        ans = max(ans, cities[k-i]);
    }
    cout << ans << '\n';
}