#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long b1, q, l, m;
    cin >> b1 >> q >> l >> m;
    set<int> s;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    int cnt = 0;
    for (int i = 0; i < 1000; i++) {
        if (abs(b1) > l) {
            cout << cnt << endl;
            return 0;
        }

        if (s.count(b1) == 0)
            cnt++;

        b1 *= q;
    }

    if (cnt > 100)
        cout << "inf" << endl;
    else
        cout << cnt << endl;
}