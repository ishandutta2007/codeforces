#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int N = 0;

int n;

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
        int k;
		scanf("%d %d", &n, &k);

        int y = n / k;
        if (k * y != n) y++;

        int x = (y*k) / n;
        if (n * x != y*k) x++;

        printf("%d\n", x);
	}
	return 0;
}