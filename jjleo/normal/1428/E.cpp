#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

priority_queue<pair<ll, pair<int, int> > > q;

int n, k, x;
ll ans;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		ans += 1ll * x * x;
		q.push({1ll * x * x - 1ll * (x / 2) * (x / 2) - 1ll * ((x + 1) / 2) * ((x + 1) / 2), {x, 2}});
	}
	for(int i = 1;i <= k - n;i++){
		pair<ll, pair<int, int> > p = q.top();q.pop();
		ans -= p.first;
		//printf("%lld %d %d--\n", p.first, p.second.first, p.second.second);
		int x = p.second.first, y = ++p.second.second;
		if(y > x) continue;
		q.push({1ll * (x / (y - 1) + 1) * (x / (y - 1) + 1) * (x % (y - 1)) + 1ll * (x / (y - 1)) * (x / (y - 1)) * (y - 1 - x % (y - 1)) - 1ll * (x / y + 1) * (x / y + 1) * (x % y) - 1ll * (x / y) * (x / y) * (y - x % y), p.second});
	}
	printf("%lld", ans);
}