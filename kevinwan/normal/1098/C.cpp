#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
const int mn = 3e5 + 10;
ll n;
ll s;
bool poss(ll x) {
	ll tot=0,curp=1,cur=1,num=0;
	while (num < n) {
		if (num + cur <= n) {
			num += cur;
			tot += curp * cur;
		}
		else {
			tot += curp * (n - num);
			num = n;
		}
		curp++;
		cur *= x;
	}
	if (tot <= s)return 1;
	return 0;
}
ll k[mn],ln[mn],p[mn],num[mn],at[mn];
vector<int> pos[mn];
int main() {
	scanf("%lld%lld", &n, &s);
	if (s > n*(n + 1) / 2 || s < 2 * n - 1) {
		printf("No");
		return 0;
	}
	ll i, j;
	for (i = 1; !poss(i); i++);
	ll br = i;
	int cur = 1;
	ll curp=1,curv=1,ac=0,tar;
	for (i = 0; i < n; curv*=br,curp++) {
		ll en = min(n, i + curv);
		for (i++; i <= en; i++)k[i] = curp, ac += curp;
		i--;
	}
	tar = k[n] + 1;
	for (i = n; i; i--) {
		if (k[i] != k[i - 1])continue;
		if (ac + tar - k[i] <= s)ac+=tar-k[i],k[i]=tar;
		else k[i] += s - ac, ac = s;
		tar++;
	}
	sort(k + 1, k + n + 1);
	for (i = 1; i <= n; i++)pos[k[i]].push_back(i),num[k[i]]++;
	printf("Yes\n");
	for (i = 2; i <= n; i++) {
		p[i] = pos[k[i]-1][at[k[i]-1]++];
		at[k[i] - 1] %= num[k[i] - 1];
		printf("%d ", p[i]);
	}
}