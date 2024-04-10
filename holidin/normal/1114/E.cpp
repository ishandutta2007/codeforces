#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;
const long long inf = 4e18 + 1;

int nod(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

bool use[N];
int a[N];

int get(int n) {
    unsigned int x = (rand() << 16) + rand();
    return x % n + 1;
}

int main() {
    int i, j, m, k, n, x;
    //freopen("input.txt", "r", stdin);
    cin >> n;
        int d = 0;
        for (i = 1; i <= min(n, 30); ++i) {
            j = get(n);
            while (use[j])
                j = get(n);
            use[j] = true;
            cout << "? " << j << endl;
            cin >> x;
            a[i] = x;
            for (j = 1; j < i; ++j)
                d = nod(d, abs(a[j] - a[i]));
        }
        int l = 0, r = 1e9 + 1;
        while (r - l > 1) {
            int x = (l + r) / 2;
            cout << "> " << x - 1 << endl;
            cin >> j;
            if (j == 1)
                l = x;
            else
                r = x;
        }
        cout << "! " << l - (n - 1) * d << ' ' << d << endl;
}