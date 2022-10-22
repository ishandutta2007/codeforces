#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=5e5+9;
int n,m,q;
int a[M],f[M],t[M];
pii e[M],o[M],O[M];
set<int>s[M];
bool vis[M];
int find(int x){
	return f[x]==x?x:find(f[x]);
}
void merge(int x,int y){
	if(t[x]>t[y])swap(x,y);
	f[x]=y;
	t[y]+=t[x];
	for(auto v:s[x])s[y].insert(v);
}
vector<int>c;
void del(int x,int y){
	if(f[x]!=y)swap(x,y);
	c.clear();
	for(auto v:s[x]){
		if(s[y].find(v)==s[y].end())c.push_back(v);
		else s[y].erase(v);
	}
	for(auto v:c)s[x].erase(v);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		f[i]=i;
		t[i]=1;
		s[i].insert(a[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&e[i].fi,&e[i].se);
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&o[i].fi,&o[i].se);
		if(o[i].fi==2)vis[o[i].se]=1;
	}
	for(int i=1;i<=m;++i){
		if(!vis[i]){
			int u=e[i].fi,v=e[i].se;
			u=find(u);
			v=find(v);
			if(u==v)continue;
			merge(u,v);
		}
	}
	int mm=0;
	for(int i=q;i>=1;--i){
		if(o[i].fi==2){
			int id=o[i].se,u=e[id].fi,v=e[id].se;
			u=find(u);
			v=find(v);
			if(u==v)continue;
			e[id].fi=u;e[id].se=v;
			merge(u,v);
		}
		else o[i].se=find(o[i].se);
		O[++mm]=o[i];
	}
	for(int i=mm;i>=1;--i)o[mm-i+1]=O[i];
	q=mm;
	for(int i=1;i<=q;++i){
		if(o[i].fi==2){
			int id=o[i].se,u=e[id].fi,v=e[id].se;
			del(u,v);
		}
		else{
			int u=o[i].se;
			if(s[u].size()){
				int x=*s[u].rbegin();
				printf("%d\n",x);
				s[u].erase(x);
			}
			else puts("0");
		}
	}
	return 0;
}