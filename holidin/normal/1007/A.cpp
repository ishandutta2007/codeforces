#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

map <int, int> m;
int a[N];
int main() {
    int i, j, n, q, top, l, r;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector <int> v;
    for (i = 0; i < n; ++i) {
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    int cnt = 0, ans = 0;
    i = 0;
    while (i < v.size()) {
        int j = i;
        while (j < v.size() && v[j] == v[i]) {
            if (cnt > 0) {
                ++ans;
                --cnt;
            }
            ++j;
        }
        cnt += j - i;
        i = j;
    }
    cout << ans;
}