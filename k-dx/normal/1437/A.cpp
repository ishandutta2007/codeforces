#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 0;

int n;

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
        int l, r;
		scanf("%d %d", &l, &r);

        if (2*l > r)
            printf("YES\n");
        else
            printf("NO\n");

	}
	return 0;
}