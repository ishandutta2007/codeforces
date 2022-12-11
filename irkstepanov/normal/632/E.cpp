#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

const int amax = 1e6 + 10;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 1; i < n; ++i) {
        a[i] -= a[0];
    }

    vector<char> used(amax, false);
    used[0] = true;
    set<int> x, y;
    x.insert(0);

    for (int i = 0; i < k; ++i) {
        for (set<int>::iterator it = x.begin(); it != x.end(); ++it) {
            for (int j = 1; j < n; ++j) {
                int val = *it + a[j];
                if (!used[val]) {
                    used[val] = true;
                    y.insert(val);
                }
            }
        }
        x.clear();
        x = y;
        y.clear();
    }

    int add = k * a[0];
    for (int i = 0; i < amax; ++i) {
        if (used[i]) {
            cout << i + add << " ";
        }
    }

    cout << "\n";

}