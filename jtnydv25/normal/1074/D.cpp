#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

map<int, pii> par;
map<int, int> rnk;

pii root(int x){
	if(par.find(x)==par.end()) return {x, 0};
	auto curr = par[x];
	auto it = root(curr.F);
	return par[x] = {it.F, it.S ^ curr.S};
}

bool merge(int x, int y, int z){
	auto it1 = root(x), it2 = root(y);
	x = it1.F, y = it2.F;
	int xr = it1.S ^ it2.S;
	if(x == y && xr != z){
		return 0;
	}
	if(x == y) return 1;
	int rnkx = rnk[x], rnky = rnk[y];
	if(rnky < rnkx){
		swap(x, y);
	}
	if(rnkx == rnky) rnk[y]++;
	par[x] = {y, xr ^ z};
}

int get(int x, int y){
	auto it1 = root(x), it2 = root(y);
	x = it1.F, y = it2.F;
	int xr = it1.S ^ it2.S;
	return x != y ? -1 : xr;
}

int main(){
	int q; sd(q);
	int lst = 0;
	while(q--){
		int t, l, r, x; sd(t); sd(l); sd(r);
		l ^= lst;
		r ^= lst;
		if(l>r) swap(l,r);
		l--;
		if(t == 1){
			sd(x);
			x ^= lst;
			merge(l, r, x);

		} else{
			printf("%d\n", lst = get(l, r));
			if(lst==-1) lst = 1;
		}
	}
}