#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int a, b, c, d;
    int n, k;
    cin >> n >> k;
    cin >> a >> b >> c >> d;

    if (n == 4 || k < n + 1) {
        puts("-1");
        return 0;
    }

    vector<int> path;
    for (int i = 1; i <= n; ++i) {
        if (i != a && i != b && i != c && i != d) path.push_back(i);
    }

    printf("%d %d", a, c);
    for (int x : path) {
        printf(" %d", x);
    }
    printf(" %d %d\n", d, b);


    printf("%d %d", c, a);
    for (int x : path) {
        printf(" %d", x);
    }
    printf(" %d %d\n", b, d);


    return 0;
}