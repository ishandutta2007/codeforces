#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 500005;

llint n, sol, mn = 1e9 + 5, cnt;
int l[MAXN];

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d", &l[i]);
        if (l[i] > 0) cnt++;
        mn = min(mn, (llint) abs(l[i]));
        sol += abs(l[i]);
    }
    if (n == 1) cout << l[0]; else if (cnt == n || cnt == 0) cout << sol - 2*mn; else cout << sol;
	return 0;
}