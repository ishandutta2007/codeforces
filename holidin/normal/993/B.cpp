#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;


set <int> s;
int a[N], b[N], c[N], d[N];

int main() {
    int i, j, k, n;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }
    for (i = 0; i < k; ++i) {
        cin >> c[i] >> d[i];
        if (c[i] > d[i])
            swap(c[i], d[i]);
    }
    int ans = -1;
    for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j)
    if (!(a[i] == c[j] && b[i] == d[j])) {
        if (a[i] == c[j])
            s.insert(a[i]);
        if (a[i] == d[j])
            s.insert(a[i]);
        if (b[i] == c[j])
            s.insert(b[i]);
        if (b[i] == d[j])
            s.insert(b[i]);
    }
    if (s.size() == 1)
        cout << *s.begin();
    else {
        for (i = 0; i < n; ++i) {
            set <int> p;
            for (j = 0; j < k; ++j)
            if (!(a[i] == c[j] && b[i] == d[j])) {
                if (a[i] == c[j])
                    p.insert(a[i]);
                if (a[i] == d[j])
                    p.insert(a[i]);
                if (b[i] == c[j])
                    p.insert(b[i]);
                if (b[i] == d[j])
                    p.insert(b[i]);
            }
            if (p.size() > 1) {
                cout << -1;
                return 0;
            }
        }
        for (j = 0; j < k; ++j) {
            set <int> p;
            for (i = 0; i < n; ++i)
            if (!(a[i] == c[j] && b[i] == d[j])) {
                if (a[i] == c[j])
                    p.insert(a[i]);
                if (a[i] == d[j])
                    p.insert(a[i]);
                if (b[i] == c[j])
                    p.insert(b[i]);
                if (b[i] == d[j])
                    p.insert(b[i]);
            }
            if (p.size() > 1) {
                cout << -1;
                return 0;
            }
        }
        cout << 0;
    }
}