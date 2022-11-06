#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

int get(int n, int pos) {
    if (pos % 2 == 1) {
        return 1 + pos / 2;
    }
    pos = pos / 2;
    if (n % 2 == 1) {
        if (pos == 1) pos = n / 2;
        else --pos;
    }
    return (n + 1) / 2 + get(n / 2, pos);
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int pos; cin >> pos;
        cout << get(n, pos) << '\n';
    }

    /*int k = 6;
    int n = k * 2 + 1;
    vector<int> a(n);
    for (int i = 1; i <= k; ++i) {
        a[2 * (i - 1)] = i;
    }
    while (true) {
        int ma = n - 1;
        while (!a[ma]) --ma;
        int zero = ma;
        while (zero >= 0 && a[zero]) --zero;
        if (zero < 0) break;
        swap(a[zero], a[ma]);
    }
    for (int i = 0; i < k; ++i) cout << a[i] << ' ';*/
}