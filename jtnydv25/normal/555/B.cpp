#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define slld(x) scanf("%lld", &(x))
#define pii pair<int, int>
#define F first
#define S second

const int N = 2e5 + 10;
ll a[N], l[N], r[N];
int ans[N], perm[N];
pair<ll, ll> P[N], Q[N];

bool cmp(int i, int j){
	return P[i].S < P[j].S;
}

set<pair<ll, ll > > available;
bool done[N]; 
int main(){
	int n, m;
	sd(n); sd(m);

	for(int i = 1; i <= n; i++){
		slld(l[i]); slld(r[i]);
		if(i > 1){
			P[i - 1] = {l[i] - r[i - 1], r[i] - l[i - 1]};
			perm[i - 1] = i - 1;
		}
	}

	for(int i = 1; i <= m; i++){
		slld(a[i]);
		Q[i] = {a[i], i};
		available.insert(Q[i]);
	}

	sort(Q + 1, Q + m + 1);
	sort(perm + 1, perm + n, cmp);

	for(int i = 1; i <= n - 1; i++){
		int ind = perm[i];
		ll mn = P[ind].F;
		auto it = available.lower_bound({mn, -1});
		if(it == available.end() || (*it).F > P[ind].S){
			printf("No");
			return 0;
		}

		ans[ind] = (*it).S;
		available.erase(it);
	}

	printf("Yes\n");
	for(int i = 1; i <= n - 1; i++){
		printf("%d ", ans[i]);
	}
}