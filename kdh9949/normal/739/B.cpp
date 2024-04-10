#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, cnt;
ll a[200010], dd[200010];
pair<ll, int> d[200010];
int num[200010], en[200010];
vector<pair<int, ll> > ch[200010];
vector<ll> dat[524289];
int sz;

void ndfs(int x, ll dis){
	num[x] = ++cnt;
    d[x] = {dis - a[x], num[x]};
    dd[x] = dis;
    for(auto &i : ch[x]) ndfs(i.first, dis + i.second);
    en[x] = cnt;
}

void ins(int x, ll v){
	x += sz - 1;
	while(x){
		dat[x].push_back(v);
		x /= 2;
	}
}

void init(){
	for(sz = 1; sz < n; sz *= 2);
	for(int i = 1; i <= n; i++){
        ins(d[i].second, d[i].first);
	}
}

int query(int s, int e, ll v){
    int ret = 0;
    for(s += sz - 1, e += sz - 1; s <= e; s /= 2, e /= 2){
		if(s % 2 == 1){
			ret += upper_bound(dat[s].begin(), dat[s].end(), v) - dat[s].begin();
			s++;
		}
		if(e % 2 == 0){
			ret += upper_bound(dat[e].begin(), dat[e].end(), v) - dat[e].begin();
			e--;
		}
    }
    return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 2; i <= n; i++){
		int x, y; scanf("%d%d", &x, &y);
		ch[x].push_back({i, (ll)y});
	}
    ndfs(1, 0);
    sort(d + 1, d + n + 1);
	//for(int i = 1; i <= n; i++) printf("%lld (%d)\n", d[i].first, d[i].second);
	init();
    for(int i = 1; i <= n; i++){
		printf("%d ", query(num[i], en[i], dd[i]) - 1);
    }
}