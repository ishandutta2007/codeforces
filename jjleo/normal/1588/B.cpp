#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
map<int, ll> mp;
ll x;

ll query(int r){
	if(r == 0) return 0;
	if(mp.find(r) != mp.end()) return mp[r];
	printf("? 1 %d\n", r), fflush(stdout);
	scanf("%lld", &x);
	return mp[r] = x;
}

int get(ll x){
	int l = 1, r = n, mid;
	while(l < r){
		mid = l + r >> 1;
		if(1ll * mid * (mid - 1) / 2 >= x) r = mid;
		else l = mid + 1;
	}
	if(1ll * l * (l - 1) / 2 == x) return l;
	return -1;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mp.clear();
		int l = 2, r = n - 1, mid, ans;
		ll all = query(n);
		while(l <= r){
			mid = l + r >> 1;
			//printf("%d %d %d--\n", l, r, mid);
			ll x = query(mid);
			if(x == 0) l = mid + 1;
			else if(x == all) r = mid - 1;
			else{
				int y = get(x);
				if(y == -1) r = mid - 1;
				else if(query(mid - y + 1) == 0) l = mid + 1, ans = mid;
				else r = mid - 1;
			}
		}
		//printf("%d--\n", ans);
		int lcnt = get(query(ans)), rcnt = get(query(n) - query(ans));
		printf("! %d %d %d\n", ans - lcnt + 1, ans + 1, ans + rcnt), fflush(stdout);
	}
}