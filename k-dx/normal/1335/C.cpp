#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		vector<int> st;
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			st.push_back(temp);
		}

		sort(st.begin(), st.end());
		st.push_back(INT_MAX);

		int diffrent = 0;
		int ile = 1, maxi = 0;
		for (int i = 1; i < st.size(); i++) {
			if (st[i] != st[i-1]) {
				maxi = max(maxi, ile);
				ile = 1;

				if (i != st.size()) diffrent++;
			}
			else {
				ile++;
			}

		}
		//printf("diff = %d, maxi = %d\n", diffrent, maxi);

		int wynik = 0;
		//if (diffrent-1 >= maxi) wynik = maxi;
		//else wynik = max(min(diffrent, maxi-1), min(diffrent-1, maxi));
		wynik = max(min(diffrent, maxi-1), min(diffrent-1, maxi));


		printf("%d\n", wynik);

	}
	return 0;
}