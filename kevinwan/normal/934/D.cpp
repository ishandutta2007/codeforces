#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m(a,b) a%b>=0?a%b:a%b+b
int main() {
	vector<ll> ans;
	ll p, k;
	scanf("%lld%lld", &p, &k);
	while (p != 0) {
		ll num = m(p, k);
		ans.push_back(num);
		p -= num;
		p /= (-k);
	}
	printf("%d\n", ans.size());
	for (auto a : ans)printf("%lld ", a);
	getchar(); getchar();
}