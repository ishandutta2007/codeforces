#include <bits/stdc++.h>
//#pragma GCC optimize 03
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 3e5 + 1;

int a[N], p[N];
vector <int> v;

int main() {
    int i, j, k, n, t;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i !=  1)
            v.push_back(a[i] - a[i - 1]);
    }
    sort(v.begin(), v.end());
    long long ans = a[n] - a[1];
    for (i = v.size() - k + 1; i < v.size(); ++i)
        ans -= v[i];
    cout << ans;
}