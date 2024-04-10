#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n, mn;
int a[MAXN];
vector <int> v;

bool check () {
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] > a[i]) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        mn = 1e9;
        v.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] % mn == 0) v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        int curr = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % mn == 0) {
                a[i] = v[curr];
                curr++;
            }
        }
        if (check()) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}