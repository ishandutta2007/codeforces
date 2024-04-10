#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bit[200001],v[200001];
void u(ll a, ll b) { for (; a <= 200000; a += a & -a)bit[a] += b; }
ll q(ll a) { ll b = 0; for (; a; a -= a & -a)b += bit[a]; return b; }
int main() {
	ll n, m, i, a, b, c;
	scanf("%lld%lld", &n, &m);
	set<pair<ll, ll>> s;
	set<pair<ll, ll>>::iterator it;
	for (i = 1; i <= n; i++)scanf("%lld", &a), u(i, a), s.insert({ a,i }),v[i]=a;
	while (m--) {
		scanf("%lld", &a);
		if (a == 1) {
			scanf("%lld%lld", &a, &b);
			printf("%lld\n", q(b)-q(a-1));
		}
		else if (a == 2) {
			scanf("%lld%lld%lld", &a, &b, &c);
			ll sp = c;
			while (1) {
				it = s.lower_bound({ sp,a });
				if (it == s.end())break;
				while (1) {
					if (it == s.end()) {
						sp = 0x3f3f3f3f3f3f3f3f; break;
					}
					if ((*it).second > b ) { sp = (*it).first + 1; break; }
					if ((*it).second < a) { sp = (*it).first; break; }
					u((*it).second, (*it).first%c-(*it).first);
					v[(*it).second] = (*it).first%c;
					s.insert({ (*it).first%c,(*it).second });
					s.erase(it++);
				}
			}
		}
		else {
			scanf("%lld%lld", &a, &b);
			u(a, b - v[a]);
			s.erase({ v[a],a }), v[a] = b,  s.insert({ b,a });
		}
	}
	getchar(); getchar();
}