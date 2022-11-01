#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, q;
int a[maxn], b[maxn];
ll ans;
int x, y, z;

map<pair<int, int>, int> mp;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), ans += a[i];
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d", &x, &y, &z);
		if(mp.find({x, y}) != mp.end()) ans += min(a[mp[{x, y}]], b[mp[{x, y}]]), b[mp[{x, y}]]--, ans -= min(a[mp[{x, y}]], b[mp[{x, y}]]), mp.erase({x, y});
		if(z) mp[{x, y}] = z, ans += min(a[z], b[z]), b[z]++, ans -= min(a[z], b[z]);
		printf("%lld\n", ans);
	}	
}