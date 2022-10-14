#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const int INF = 1000000000;

llint n, sol, cnt;
int mn[MAXN], mx[MAXN];
bool ok[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int br; cin >> br;
        mn[i] = INF; mx[i] = -INF;
        bool ima = 0;
        for (int j = 0; j < br; j++) {
            int x;
            cin >> x;
            if (x > mn[i]) ima = 1;
            mn[i] = min(mn[i], x);
            mx[i] = max(mx[i], x);
        }
        ok[i] = ima;
        if (ima) cnt++; else v.push_back(mx[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (ok[i]) continue;
        int ind = upper_bound(v.begin(), v.end(), mn[i]) - v.begin();
        sol += v.size() - ind;
    }
    cout << sol + cnt * cnt + 2 * cnt * (n - cnt);
    return 0;
}