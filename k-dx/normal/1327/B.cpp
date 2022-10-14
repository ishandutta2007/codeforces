#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

bool chl[N], dziew[N];

int main () {
	int ti;
	scanf("%d", &ti);

	while (ti--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int k;
			scanf("%d", &k);

			for (int j = 0; j < k; j++) {
				int temp;
				scanf("%d", &temp);

				if (!dziew[i] and !chl[temp-1]) {
					chl[temp-1] = true;
					dziew[i] = true;
				}
			}
		}

		int dziew_bez = -1, chl_bez = -1;
		for (int i = 0; i < n; i++) {
			if (!chl[i]) chl_bez = i;
			if (!dziew[i]) dziew_bez = i;
		}

		if (dziew_bez != -1 and chl_bez != -1) {
			printf("IMPROVE\n");
			printf("%d %d\n", dziew_bez+1, chl_bez+1);
		}
		else {
			printf("OPTIMAL\n");
		}

		for (int i = 0; i < n+1; i++) {
			chl[i] = false;
			dziew[i] = false;
		}

	}

	return 0;
}