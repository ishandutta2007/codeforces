#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5;

int a[N];
set <pair<int, int> > s;

int main() {
    int i, j, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int top = 1;
    for (i = 1; i <= n; ++i)
        s.insert({0, i});
    for (i = 0; i < k; ++i) {
        cin >> j;
        s.erase({a[j], j});
        ++a[j];
        s.insert({a[j], j});
        if ((*s.begin()).fi >= top) {
            cout << 1;
            ++top;
        } else
            cout << 0;
    }
}