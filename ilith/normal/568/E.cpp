#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=2e5+7,inf=1e9+7;
int n,m,b[N],C,ls[N],rs[N];
multiset<int>u;
struct node{
	int v,p;
	bool operator<(node x)const{return v<x.v;}
};
node s[N],a[N],t;
set<int>ct[N];
signed main(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",rs+i),a[i]={rs[i],i};
	scanf("%d",&m);
	FOR(i,1,m)scanf("%d",b+i),u.insert(b[i]);
	sort(b+1,b+m+1,[](int x,int y){return x>y;});
	m=unique(b+1,b+m+1)-b-1;
	FOR(i,1,n)if(~rs[i]){
		if(s[C]<a[i])s[ls[i]=++C]=a[i],ct[C].insert(i);
		else{
			int p=ls[i]=lower_bound(s+1,s+C+1,a[i])-s;
			if(rs[i]<s[p].v)s[p]=a[i],ct[p].insert(i);
		}
	}
	else{
		if(b[1]>s[C].v)s[++C]={b[1],i};
		int p=C;
		FOR(j,1,m){
			while(p&&s[p-1].v>=b[j])--p;
			if(b[j]<s[p].v)s[p]={b[j],i};
		}
	}
	for(int x=s[C].p,nw=inf,lb=1;x;){
		if(~rs[x]){
			if(rs[x]<nw&&ls[x]==C)--C,nw=rs[x];
		}
		else{
			FOR(i,1,m)if(b[i]<nw){
				--C,nw=rs[x]=b[i],u.erase(u.find(nw));
				break;
			}
		}
		while(b[lb]>=nw&&lb<=m)++lb;
		auto it=ct[C].lower_bound(x);
		if(it==ct[C].begin())--x;
		else{
			int y=*prev(it);
			if(rs[y]>=nw||rs[y]<b[lb])--x;
			else x=y;
		}
	}
	FOR(i,1,n){
		if(rs[i]==-1)rs[i]=*u.begin(),u.erase(u.begin());
		printf("%d ",rs[i]);
	}
	return 0;
}