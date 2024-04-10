#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a, d;
int c[100];
bool u[100];
int main() {
	int n, m,i,j,x;
	string s;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		cin >> s;
		scanf("%d", &x);
		if (s[0] == 'A')a.push_back(x);
		else d.push_back(x + 1);
	}
	sort(a.begin(), a.end());
	sort(d.begin(), d.end());
	for (i = 0; i < m; i++)scanf("%d", c + i);
	sort(c, c + m);
	int ans = 0,cur=0,poss=0;
	for (i = 0; i < m&&cur < d.size(); i++) {
		if (c[i] >= d[cur])u[i] = 1, cur++;
	}
	if (cur != d.size())poss = -0x3f3f3f3f;
	if (n > m)poss = -0x3f3f3f3f;
	cur = a.size()-1;
	for (i = m-1; i >=0&&cur>=0; i--) {
		if (u[i])continue;
		if (c[i] < a[cur])poss = -0x3f3f3f3f;
		else poss += c[i] - a[cur];
		u[i] = 1;
		cur--;
	}
	for (i = 0; i < m; i++)if (!u[i])poss += c[i];
	ans = max(ans, poss);
	for (i = 1; i <= min((int)a.size(),m); i++) {
		poss = 0;
		for (j = 1; j <= i; j++) {
			if (c[m - j] < a[i - j])poss = -0x3f3f3f3f;
			else poss += c[m - j] - a[i - j];
		}
		ans = max(ans, poss);
	}
	if (ans < 0)ans = 0;
	printf("%d", ans);
	getchar(); getchar();
}