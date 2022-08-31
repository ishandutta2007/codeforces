#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

map<int,int> mp;

struct disj{
	int pa[200005];
	void init(int n){
		for(int i=0; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		pa[find(p)] = find(q);
	}
}disj;

int fp(int b){
	return (--mp.upper_bound(b))->second;
}
int main(){
	int n, q;
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++){
		mp[i] = i;
	}
	disj.init(n);
	while(q--){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		if(a == 3){
			int t = fp(b), u = fp(c);
			puts(disj.find(t) == disj.find(u) ? "YES":"NO");
		}
		if(a == 1){
			int t = fp(b), u = fp(c);
			disj.uni(t, u);
		}
		if(a == 2){
			auto t = --mp.upper_bound(b);
			auto obj= --mp.upper_bound(c);
			while(t != obj){
				auto u = t;
				u++;
				disj.uni(t->second , u->second);
				t->second = u->second;
				if(u == obj){
					mp.erase(u);
					break;
				}
				mp.erase(u);
			}
		}
	}
}