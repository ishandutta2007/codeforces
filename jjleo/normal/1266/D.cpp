#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, m;
int x, y, z;
ll a[maxn];
vector<tuple<int, int, ll> > v;
vector<int> w[2];

int main(){
	scanf("%d%d", &n, &m);
	while(m--) scanf("%d%d%d", &x, &y, &z), a[x] += z, a[y] -= z;
	for(int i = 1;i <= n;i++) if(a[i]) w[a[i] > 0].push_back(i), a[i] = abs(a[i]);
	while(!w[0].empty()){
		ll val = min(a[w[0].back()], a[w[1].back()]);
		v.push_back(make_tuple(w[1].back(), w[0].back(), val));
		a[w[0].back()] -= val, a[w[1].back()] -= val;
		if(!a[w[0].back()]) w[0].pop_back();
		if(!a[w[1].back()]) w[1].pop_back();
	}
	printf("%d\n", v.size());
	for(auto x : v) printf("%d %d %lld\n", get<0>(x), get<1>(x), get<2>(x));
}