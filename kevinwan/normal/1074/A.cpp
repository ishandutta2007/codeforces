#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
#define mn (1<<17)
vector<int> v,h;
int main() {
	int ans = 0x3f3f3f3f;
	int n, m,i,a,b,c;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)scanf("%d", &a), v.push_back(a);
	v.push_back(1e9);
	sort(v.begin(), v.end());
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)h.push_back(b);
	}
	sort(h.begin(), h.end());
	int cur = -1;
	for (i = 0; i < v.size(); i++) {
		while (cur+1<h.size()&&h[cur + 1] < v[i])cur++;
		ans = min((unsigned int)ans, i + h.size() - cur - 1);
	}
	printf("%d", ans);
	getchar(); getchar();
}