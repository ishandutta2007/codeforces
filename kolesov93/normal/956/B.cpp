#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n, u;
    cin >> n >> u;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int last = 0;
    ll bA = -1, bB = 1;
    for (int i = 0; i + 2 < n; ++i) {
        while (last < n && a[last] - a[i] <= u) ++last;
        if (last - i < 3) continue;

        ll A = a[last - 1] - a[i + 1];
        ll B = a[last - 1] - a[i];
        if (bA == -1 || A * bB > B * bA) {
            bA = A;
            bB = B;
        }
    }
    if (bA == -1) {
        puts("-1");
        return 0;
    }
    cout.precision(15);
    cout << fixed;
    cout << static_cast<long double>(bA) / bB << endl;


    return 0;
}