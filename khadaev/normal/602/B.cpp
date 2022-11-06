#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	vector<int> groups, lens;
	int i = 0;
	while (i < n) {
		groups.push_back(a[i]);
		int j = i;
		while (j < n && a[j] == a[i]) ++j;
		lens.push_back(j - i);
		i = j;
	}
	vector<int> breaks = {0};
	for (int i = 1; i < groups.size() - 1; ++i) {
		if (groups[i] > groups[i - 1] && groups[i + 1] > groups[i]) breaks.push_back(i);
		if (groups[i] < groups[i - 1] && groups[i + 1] < groups[i]) breaks.push_back(i);
	}
	breaks.push_back(groups.size() - 1);
	//for (int i : groups) cerr << i << '\n';
	/*cerr << '\n';
	for (int i : lens) cerr << i << '\n';
	cerr << '\n';
	for (int i : breaks) cerr << i << '\n';
	cerr << '\n';*/
	int ans = 0;
	for (int i = 0; i < breaks.size() - 1; ++i) {
		int sum = 0;
		for (int j = breaks[i]; j <= breaks[i + 1]; ++j) sum +=
			lens[j];
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
}