#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, m;
int a[maxn];
set<int> st;
map<int, ll> mp;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++){
		int x;
		scanf("%d", &x);
		st.insert(x);
	}
	for(int i = 1;i <= n;i++){
		int x = (i - 1) * 100;
		set<int>::iterator it = st.lower_bound(x);
		int r = 1e9, l = -1e9;
		if(it != st.end() && *it == x) continue;
		if(it != st.end()) r = *it;
		if(it != st.begin()) l = *prev(it);
		if(x - l > r - x) l = x - (r - x);
		else r = x + (x - l);
		mp[l] += a[i];
		mp[r] -= a[i];
	}
	ll ans = 0, sum = 0;
	for(auto it : mp){
		sum += it.second;
		ans = max(ans, sum);
	}
	printf("%lld", ans);
}