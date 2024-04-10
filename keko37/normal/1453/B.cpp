#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n;
int a[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i >= 2) v.push_back(a[i] - a[i - 1]);
        }
        llint sum = 0;
        for (auto x : v) sum += abs(x);
        llint sol = sum;
        sol = min(sol, sum - abs(v[0]));
        sol = min(sol, sum - abs(v.back()));
        for (int i = 1; i < v.size(); i++) {
            if (v[i] >= 0 && v[i - 1] <= 0 || v[i] <= 0 && v[i - 1] >= 0) {
                sol = min(sol, sum - 2 * min(abs(v[i]), abs(v[i - 1])));
            }
        }
        cout << sol << '\n';
    }
    return 0;
}