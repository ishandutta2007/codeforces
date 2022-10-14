#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int MOD = 998244353;

llint n, k, sum, sol = 1;
int p[MAXN], pos[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
        sum += n + 1 - i;
        v.push_back(pos[n + 1 - i]);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        sol = sol * (v[i] - v[i - 1]) % MOD;
    }
    cout << sum << " " << sol;
    return 0;
}