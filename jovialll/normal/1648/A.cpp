#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
struct node{
	int x,v;
}f[N];
ll l1,l2,ans,z[N];
int n,m,i,j,cnt;
inline bool cmp(node aa,node bb){
	if(aa.v==bb.v){
		return aa.x<bb.x;
	}
	return aa.v<bb.v;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			f[++cnt].x=i;
			cin>>f[cnt].v;
			z[cnt]=f[cnt].v; 
		}
	}
	sort(f+1,f+cnt+1,cmp);
	for(i=1;i<=cnt;++i){
		ans+=(i-l1-1)*f[i].x-l2;
		l2+=f[i].x;
		if(f[i].v!=f[i+1].v){
			l1=i;
			l2=0;
		}
	}
	cnt=0;l1=l2=0;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			f[++cnt].x=j;
			f[cnt].v=z[cnt];
		}
	}
	sort(f+1,f+cnt+1,cmp);
	for(i=1;i<=cnt;++i){
		ans+=(i-l1-1)*f[i].x-l2;
		l2+=f[i].x;
		if(f[i].v!=f[i+1].v){
			l1=i;
			l2=0;
		}
	} 
	l1=l2=0;
	cout<<ans;
}