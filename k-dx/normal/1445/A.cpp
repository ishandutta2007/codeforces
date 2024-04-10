#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
        int x;
		scanf("%d %d", &n, &x);
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i]+b[i] > x) {
                printf("No\n");
                ok = false;
                break;
            }
        }
        if (ok) printf("Yes\n");
	}

	return 0;
}