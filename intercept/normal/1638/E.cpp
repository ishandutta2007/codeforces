#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+9;
int n,m;
ll a[M],v[M];
struct P{
	int l,r,c;
	bool operator < (const P&o)const{
		return l<o.l;
	}
};
set<P>s;
vector<P>de,ad;
void add(int p,ll t){
	for(;p<=n;p+=p&-p)a[p]+=t;
}
ll sum(int p,ll rex=0){
	for(;p;p-=p&-p)rex+=a[p];
	return rex;
}
void add(P o){
	s.insert(o);
	add(o.l,-v[o.c]);
	add(o.r+1,v[o.c]);
}
void del(P o){
	s.erase(o);
	add(o.l,v[o.c]);
	add(o.r+1,-v[o.c]);
}
int main(){
	scanf("%d%d",&n,&m);
	s.insert(P{1,n,1});
	s.insert(P{n+1,n+1,0});
	for(int i=1;i<=m;++i){
		char c[9];
		scanf("%s",c);
		if(c[0]=='C'){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			auto it=s.upper_bound(P{l,l,l});
			it--;
			de.clear(),ad.clear();
			while(it!=s.end()&&(*it).l<=r){
				P o=*it;
				de.emplace_back(o);
				if(o.l<l)ad.emplace_back(P{o.l,l-1,o.c});
				if(o.r>r)ad.emplace_back(P{r+1,o.r,o.c});
				it++;
			}
			for(auto o:de)del(o);
			for(auto o:ad)add(o);
			add(P{l,r,c});
		}
		if(c[0]=='A'){
			int c,p;
			scanf("%d%d",&c,&p);
			v[c]+=p;
		}
		if(c[0]=='Q'){
			int p;
			scanf("%d",&p);
			auto it=s.upper_bound(P{p,p,p});
			it--;
			printf("%lld\n",sum(p)+v[(*it).c]);
		}
	}
	return 0;
}