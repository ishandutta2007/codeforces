#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> a;

bool ok(int pos)
{
    if (pos % 2 == 1 && a[pos] <= a[pos + 1]) {
        return false;
    }
    if (pos % 2 == 0 && a[pos] >= a[pos + 1]) {
        return false;
    }
    return true;
}

bool check(int pos)
{
    for (int i = max(pos - 1, 0); i <= min(pos + 1, n - 2); ++i) {
        if (!ok(i)) {
            return false;
        }
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> bad;
    for (int i = 0; i < n - 1; ++i) {
        if (!ok(i)) {
            bad.pb(i);
        }
    }

    if (sz(bad) >= 5) {
        cout << "0\n";
        return 0;
    }

    set<pii> ans;

    for (int pos : bad) {
        for (int i = max(pos - 1, 0); i <= min(pos + 1, n - 1); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                swap(a[i], a[j]);
                bool flag = true;
                for (int x : bad) {
                    if (!check(x)) {
                        flag = false;
                        break;
                    }
                }
                if (!check(j)) {
                    flag = false;
                }
                if (!check(i)) {
                    flag = false;
                }
                if (flag) {
                    ans.insert(mp(min(i, j), max(i, j)));
                }
                swap(a[i], a[j]);
            }
        }
    }

    cout << sz(ans) << "\n";

}