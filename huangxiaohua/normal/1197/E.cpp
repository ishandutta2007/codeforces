#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,l,r;
ll res=1e18,ans,tmp,tmp2;
struct sb{
	ll w=0,num=1;
	vector<int> v;
};

map<int,sb> mp;
set<int> s;

int main(){
	scanf("%d",&n);
	s.insert(1145141919);
	for(i=1;i<=n;i++){
		scanf("%d%d",&r,&l);
		s.insert(l);
		mp[l].v.push_back(r);
	}
	for(auto i:s){
		ll wt=mp[i].w,nu=mp[i].num;
		if(!tmp&&!wt){goto aaa;}
		if(tmp==wt){nu+=tmp2;tmp2=nu;}
		if(tmp>wt){wt=tmp;nu=tmp2;}
		else{tmp=wt;tmp2=nu;}
		aaa:;
		mp[i].w=wt;mp[i].num=nu;
		for(auto j:mp[i].v){
			auto it=s.lower_bound(j);
			if(*it==1145141919){res=min(res,i-wt);continue;}
			if(mp[*it].w==j-i+wt){
				mp[*it].num+=nu;mp[*it].num%=M;continue;
			}
			if(mp[*it].w<j-i+wt){
				mp[*it].w=j-i+wt;
				mp[*it].num=nu;continue;
			}
		}
	}
	for(auto i:s){
		ll wt=mp[i].w,nu=mp[i].num;
		for(auto j:mp[i].v){
			auto it=s.lower_bound(j);
			if(i-wt==res&&(*it)==1145141919){
				ans+=nu;
			}
		}
	}
	printf("%lld",ans%M);
}