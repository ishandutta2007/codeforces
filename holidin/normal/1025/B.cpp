#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int i, j, n, a, b;;
bool c[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector <int> v, vv;
    for (i = 0; i < N; ++i)
        c[i] = false;
    set <int> s1, s2, s3;
    for (i = 2; i < N; ++i)
    if (!c[i]) {
        v.push_back(i);
        for (j = 1; i * j < N; ++j)
            c[i * j] = true;
    }
    cin >> n;
    cin >> a >> b;
    for (i = 0; v[i] * v[i] <=  a; ++i)
    if (a % v[i] == 0) {
        while (a % v[i] == 0)
            a /= v[i];
        vv.push_back(v[i]);
    }
    if (a > 1)
        vv.push_back(a);
    a = b;
    for (i = 0; v[i] * v[i] <=  a; ++i)
    if (a % v[i] == 0) {
        while (a % v[i] == 0)
            a /= v[i];
        vv.push_back(v[i]);
    }
    if (a > 1)
        vv.push_back(a);
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        j = 0;
        while (j < vv.size())
        if (a % vv[j] == 0 || b % vv[j] == 0)
            ++j;
        else {
            swap(vv[j], vv[vv.size() - 1]);
            vv.resize(vv.size() - 1);
        }
    }
    if (vv.size() == 0)
        cout << -1;
    else
        cout << vv[0];

}