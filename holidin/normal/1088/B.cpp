#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e3;

vector <int> v;

int main() {
    int i, j, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    j = 0;
    int vi = 0;
    for (i = 0; i < k; ++i) {
        while (j < v.size() && v[j] <= vi)
            ++j;
        if (j == v.size())
            cout << 0 << "\n";
        else
            cout << v[j] - vi << "\n";
        vi += v[j] - vi;
    }
}