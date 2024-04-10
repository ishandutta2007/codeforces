#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> k[10];
vector<int> num, cp;
int get(int a, int b) {
	cp = num;
	int ans = 0;
	if (b == 0)ans = a;
	else if (a < b)ans = a + b - 1;
	else ans = a + b;
	cp.erase(cp.begin()+max(a, b));
	cp.erase(cp.begin()+min(a, b));
	int ln = -0x3f3f3f3f;
	if (cp.size() == 0)ln = -1;
	for (int i = 0; i < cp.size(); i++)if (cp[i] != 0)ln = i;
	return ans + cp.size() - ln - 1;
}
int main() {
	ll n;
	scanf("%lld", &n);
	int i;
	for (i = 0; n; n /= 10, i++)k[n % 10].push_back(i), num.push_back(n % 10);
	int ans = 0x3f3f3f3f;
	for (int x : k[0])for (int y : k[0])if (x != y)ans = min(ans, get(x, y));
	for (int x : k[2])for (int y : k[5])ans = min(ans, get(y, x));
	for (int x : k[5])for (int y : k[0])ans = min(ans, get(y, x));
	for (int x : k[7])for (int y : k[5])ans = min(ans, get(y, x));
	printf("%d", ans > 10000 ? -1 : ans);
}