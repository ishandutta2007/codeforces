#include <bits/stdc++.h>
using namespace std;

struct S
{
    string str;
    int s = 0, h = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<S> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i].str;
        for (char c : t[i].str) {
            if (c == 's')
                t[i].s++;
            else 
                t[i].h++;
        }
    }

    sort(t.begin(), t.end(), [](auto p, auto q) {
        if (p.h == 0)
            return q.h > 0;
        return p.s * q.h > p.h * q.s;
    });

    int s = 0;
    int h = 0;
    long long res = 0;
    for (auto x : t) {
        for (char c : x.str) {
            if (c == 's') {
                s++;
            } else {
                h++;
                res += s;
            }
        }
    }

    cout << res << '\n';
}