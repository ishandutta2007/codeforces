#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);

	while (t--) {
		//printf("-----------\n");
		int n;
		scanf("%d", &n);

		vector<int> c;
		for (int i = 0; i < n; i++) {
			int x; 
			scanf("%d", &x);

			c.push_back(x);
		}

		int pop = c[0];
		int left = 1, right = c.size()-1;
		int a = c[0], b = 0, moves = 1;

		while (left <= right) {
			int akt = 0;

			//bob
			if (akt <= pop and left <= right) moves++;
			while (akt <= pop and left <= right) {
				//printf("bob zjada %d\n", c[right]);
				akt += c[right];
				b += c[right];

				right--;
			}

			pop = akt;
			akt = 0;

			//alice
			if (akt <= pop and left <= right) moves++;
			while (akt <= pop and left <= right) {
				//printf("alice zjada %d\n", c[left]);
				akt += c[left];
				a += c[left];

				left++;
			}

			pop = akt;
		}

		printf("%d %d %d\n", moves, a, b);

	}

	return 0;
}