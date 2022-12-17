#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define double long double
using namespace std;
const int N = 3e5 + 1;
const int mod = 1e9 + 7;

int type[N];
vector <int> vv;
int k;
int cntt = 0;
bool quer(int x) {
    ++cntt;
    #ifdef local
        bool was = 0;
        for (int i = max((int)0, (int) vv.size() - k); i < vv.size(); ++i)
        if (vv[i] == type[x])
            was = 1;
        vv.push_back(type[x]);
        return was;
    #endif
    cout << "? " << x << endl;
    char ans;
    cin >> ans;
    return ans == 'Y';
}

void clr() {
    #ifdef local
        vv.clear();
    #endif // local
    cout << "R" << endl;
}

vector <int> rec(int l, int r) {
    if (l + 1 == r) {
        vector <int> v;
        v.push_back(l);
        return v;
    } if (r - l <= k) {
        clr();
        vector <int> v;
        for (int i = l; i < r; ++i)
        if (!quer(i))
            v.push_back(i);
        return v;
    }else {
        vector <int> v2 = rec((l + r) / 2, r);
        clr();
        vector <int> v1 = rec(l, (l + r) / 2);
        vector <int> v;
        for (int i = 0; i < v1.size(); ++i)
            v.push_back(v1[i]);
        vector <int> use(v2.size());
        for (int i = 0; i < v2.size(); ++i)
            use[i] = 0;
        for (int i = 0; i * ((k + 1) / 2) < v1.size(); ++i) {
            clr();
            for (int j = 0; j < v2.size(); ++j) {
                if (j % ((k + 1) / 2) == 0) {
                    for (int l = i * ((k + 1) / 2); l < min((i + 1) * ((k + 1) / 2), (int)v1.size()); ++l)
                        quer(v1[l]);
                }
                if (quer(v2[j])) {
                    use[j] = 1;
                }
            }
        }
        for (int i = 0; i < v2.size(); ++i)
        if (use[i] == 0)
            v.push_back(v2[i]);
        return v;
    }
}

void solve() {
    int i, j, n;
    cin >> n >> k;
    #ifdef local
        for (i = 1; i <= n; ++i)
            cin >> type[i];

    #endif // local
    vector <int> v = rec(1, n + 1);
    cout << "! " << v.size() << endl;
    cout << cntt << ' ' << 2 * n * n / k << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
        solve();
}