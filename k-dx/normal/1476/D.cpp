#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int N = 300005;

int n, a[N], b[N];
char t[N];

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
		scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &t[i]);
        }

        a[0] = 1;
        if (t[0] == 'L') a[1] = 2;
        else a[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (t[i-2] == 'R' and t[i-1] == 'L') {
                a[i] = a[i-2] + 2;
            }
            else if (t[i-1] == 'L') {
                a[i] = 2;
            }
            else {
                a[i] = 1;
            }
        }

        b[n] = 1;
        if (t[n-1] == 'R') b[n-1] = 2;
        else b[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (t[i] == 'R' and t[i+1] == 'L' ) {
                b[i] = b[i+2] + 2;
            }
            else if (t[i] == 'R') {
                b[i] = 2;
            }
            else {
                b[i] = 1;
            }
        }

        for (int i = 0; i <= n; i++) {
            printf("%d ", a[i] + b[i] - 1);
        }
		printf("\n");
		
	}
	return 0;
}