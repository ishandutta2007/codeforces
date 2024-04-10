#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;

vector <long long> v;

int main() {
    long long i, j, n, k, m;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 0; i < n; ++i) {
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    long long ans = (m / (k + 1)) * (v[v.size() - 1] * k + v[v.size() - 2]) + (m % (k + 1)) * v[v.size() - 1];
    cout << ans;
}