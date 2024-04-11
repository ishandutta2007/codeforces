#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 70;
int a[N], b[N];
ll f[N][2][2];
bool u[N][2][2];
ll who, bst;
ll L, R;

void check(ll x) {
    if (x < L || x > R) return;
    int cnt = 0; ll y = x;
    while (y) {
        if (y & 1) ++cnt;
        y >>= 1;
    }
    if (bst < cnt || (bst == cnt && who > x)) {
        bst = cnt;
        who = x;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        who = bst = -1;
        ll l, r;
        cin >> l >> r;
        L = l; R = r;
        check(l); check(r);

        for (int i = 0; i < N; ++i) {
            a[i] = (l & 1);
            b[i] = (r & 1);
            l >>= 1;
            r >>= 1;
        }
        //reverse(a, a + N)
        //reverse(b, b + N)

        r = R;
        while (r) {
            check(r);
            check(r - 1);

            r &= (r - 1);
        }

        cout << who << endl;
    }

    return 0;
}