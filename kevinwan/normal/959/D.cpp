#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int u[1500000], isp[1500000];
vector<int> pf[1500000];
int a[100000], b[100000];
bool suc(int x) {
	if (u[x])return 0;
	for (int p : pf[x])if (u[p])return 0;
	return 1;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", a + i);
	memset(isp, 1, sizeof(isp));
	for (i = 2; i*2 < 1500000; i++)if (isp[i])for (j = i *2; j < 1500000; j += i)pf[j].push_back(i), isp[j] = 0;
	for (i = 0; i < n; i++) {
		b[i] = a[i];
		while (!suc(b[i]))b[i]++;
		for (int p : pf[b[i]])u[p] = 1;
		u[b[i]] = 1;
		if (b[i] != a[i])break;
	}
	i++;
	for (j = 2; i < n; j++) {
		if (!suc(j))continue;
		b[i] = j;
		for (int p : pf[j])u[p] = 1;
		u[j] = 1;
		i++;
	}
	for (i = 0; i < n; i++)printf("%d ", b[i]);
}