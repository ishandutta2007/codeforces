#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;

int t, n;
int a[MAXN], cnt[MAXN], pos[MAXN], sol[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cnt[i] = sol[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
            cnt[a[i]]++;
        }
        int lo = 1, hi = n;
        for (int k = n; k >= 2; k--) {
            int val = n + 1 - k;
            if (cnt[val] == 0) break;
            sol[k] = 1;
            if (cnt[val] >= 2 || (lo < pos[val] && pos[val] < hi)) break;
            if (lo == pos[val]) lo++; else hi--;
        }
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] != 1) ok = 0;
        }
        sol[1] = ok;
        for (int i = 1; i <= n; i++) cout << sol[i]; cout << '\n';
    }
    return 0;
}