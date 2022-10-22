#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int main() {
	int q,a;
	ll b,sum=0,cur=0;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%lld", &b);
			v.push_back(b);
			if(v.size()>=2)sum += b - v[v.size() - 2];
			else sum += b;
			while (cur < v.size() - 1 && v[cur] * (cur + 1) < sum)sum+=v[cur],cur++;
		}
		else {
			printf("%lf\n", b-(double)sum / (cur + 1));
		}
	}
}