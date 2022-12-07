#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 500555;
typedef long long ll;
typedef pair<int, int> pii;
int a[N], ls[N], rs[N];
pii where[N];
vector<int> order;

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        where[i - 1].first = a[i];
        where[i - 1].second = i;

        ls[i] = i - 1;
        rs[i] = i + 1;
    }
    rs[0] = 1; ls[n + 1] = n;
    sort(where, where + n);

    int lb = 1, rb = n;
    ll ans = 0;
    for (int ps = 0; ps + 2 < n; ++ps) {
        int pos = where[ps].second;

        if (pos == lb || pos == rb) {
            ans += a[pos];
        } else {
            ans += min(a[ ls[pos] ], a[ rs[pos] ]);
        }

        ls[ rs[pos] ] = ls[pos];
        rs[ ls[pos] ] = rs[pos];
        lb = rs[0];
        rb = ls[n + 1];
    }

    cout << ans << endl;

    return 0;
}