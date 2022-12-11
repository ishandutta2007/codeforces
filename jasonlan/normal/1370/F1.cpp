#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1024;
int n,a,b;
int rt,dis,odow;
int fa[maxn],dep[maxn],mdep;
int ans[2];
vector<int> v[maxn],d[maxn];
void dfs(int p){
	d[dep[p]].push_back(p);
	mdep=max(mdep,dep[p]);
	for(register int i:v[p])
		if(i!=fa[p]){
			dep[i]=dep[p]+1;
			fa[i]=p;
			dfs(i);
		}
}
void output(int dx){
	cout<<"? "<<d[dx].size();
	for(register int i:d[dx])
		cout<<" "<<i;
	cout<<endl;cout.flush();
	scanf("%d%d",&a,&b);
}
void process(){
	scanf("%d",&n);
	mdep=0;
	for(register int i=1;i<=n;++i){
		v[i].clear();d[i].clear();
		fa[i]=dep[i]=0;
	}
	for(register int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		v[y].push_back(x);
		v[x].push_back(y);
	}
	cout<<"? "<<n;
	for(register int i=1;i<=n;++i)
		cout<<" "<<i;
	cout<<endl;cout.flush();
	scanf("%d%d",&rt,&dis);
	dfs(rt);
	int l=0,r=mdep,mid;
	int ld,old,rd,ord;
	while(l<r){
		mid=(l+r+1)>>1;
		output(mid);
		if(b>dis){
			rd=mid;ord=a;r=mid-1;
		}
		else{
			ld=mid;old=a;l=mid;
		}
	}
	if(ld==l)odow=old;
	else odow=ord;
	while(dep[odow]<l)odow=fa[odow];
	ans[0]=odow;
	dis-=dep[ans[0]];
	while(dep[odow]>dis)odow=fa[odow];
	if(odow==rt)ans[1]=rt;
	else{
		cout<<"? "<<d[dis].size()-1;
		for(register int i:d[dis])
			if(i^odow)cout<<" "<<i;
		cout<<endl;cout.flush();
		scanf("%d%d",&ans[1],&b);
	}
	cout<<"! "<<ans[0]<<" "<<ans[1]<<endl;
	cout.flush();
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		process();
		string op;cin>>op;
	}
	return 0;
}