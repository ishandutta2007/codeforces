#include<bits/stdc++.h>
using namespace std;
int n,s;
int f[2009],id[2009];
struct P{
	int x,y,v;long double p;
}a[2009];
vector<pair<int,int>>ans;
bool cmp(int l,int r){
	return a[l].p<a[r].p;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		f[i]=i,id[i]=i;
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
	}
	for(int i=1;i<=n;++i)f[find(i)]=find(a[i].v);
	a[0].x=1e9;
	for(int i=1;i<=n;++i)if(a[i].x<a[s].x&&a[i].v!=i)s=i;
	for(int i=1;i<=n;++i){
		if(i!=s&&a[i].v!=i)a[i].p=asin((long double)(a[i].y-a[s].y)/sqrt((long double)(a[i].y-a[s].y)*(a[i].y-a[s].y)+(long double)(a[i].x-a[s].x)*(a[i].x-a[s].x)));
		else a[i].p=-1e9;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<n;++i){
		int x=id[i],y=id[i+1];
		if(a[x].p==-1e9)continue;
		if(find(x)!=find(y))f[find(x)]=find(y),ans.emplace_back(x,y),swap(a[x].v,a[y].v);
	}
	while(a[s].v!=s){
		ans.emplace_back(s,a[s].v);
		swap(a[s].v,a[a[s].v].v);
	}
	printf("%d\n",ans.size());
	for(auto o:ans)printf("%d %d\n",o.first,o.second);
	return 0;
}