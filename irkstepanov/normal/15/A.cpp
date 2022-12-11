#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

bool intersect(int a, int b, int c, int d)
{
    if (b <= c) {
        return false;
    }
    if (a >= d) {
        return false;
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    t *= 2;

    vector<int> x(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> a[i];
        x[i] *= 2, a[i] *= 2;
    }

    set<int> lf;

    for (int i = 0; i < n; ++i) {
        bool ok = true;
        int l = x[i] + a[i] / 2;
        int r = l + t;
        for (int j = 0; j < n; ++j) {
            if (intersect(x[j] - a[j] / 2, x[j] + a[j] / 2, l, r)) {
                ok = false;
            }
        }
        if (ok) {
            lf.insert(l);
        }
    }

    for (int i = 0; i < n; ++i) {
        int r = x[i] - a[i] / 2;
        int l = r - t;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (intersect(x[j] - a[j] / 2, x[j] + a[j] / 2, l, r)) {
                ok = false;
            }
        }
        if (ok) {
            lf.insert(l);
        }
    }

    cout << sz(lf) << "\n";

}