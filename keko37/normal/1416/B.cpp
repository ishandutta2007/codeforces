#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 10005;

int t, n;
int a[MAXN];
vector < pair <pi, int> > v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n != 0) {
            cout << "-1\n";
            continue;
        }
        v.clear();
        for (int i = 2; i <= n; i++) {
            int ost = 0;
            if (a[i] % i != 0) ost = i - a[i] % i;
            v.push_back({{1, i}, ost});
            v.push_back({{i, 1}, (a[i] + ost) / i});
            a[1] += a[i];
        }
        for (int i = 2; i <= n; i++) {
            v.push_back({{1, i}, sum / n});
        }
        cout << v.size() << '\n';
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << '\n';
        }
    }
    return 0;
}