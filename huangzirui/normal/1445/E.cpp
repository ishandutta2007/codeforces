#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
const int maxn=500005,maxe=2000005;
int n,m,k,t,ans,top,tot;
int xx[maxn],yy[maxn],kk[maxn],no[maxn],rec[maxe];
vector<int>q[maxn];
map<pair<int,int>,int>mp;
struct dsu{
	int fa,sz;
}f[maxn<<1],stk[maxe];
int find(int x){
	return f[x].fa==x? x:find(f[x].fa);
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(f[a].sz>f[b].sz)
		swap(a,b);
	rec[++top]=a,stk[top]=f[a],rec[++top]=b,stk[top]=f[b];
	f[a].fa=b,f[b].sz+=f[a].sz;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&kk[i]);
	for(int i=1;i<=2*n;i++)
		f[i].fa=i,f[i].sz=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&xx[i],&yy[i]);
		if(kk[xx[i]]==kk[yy[i]]){
			if(find(xx[i])==find(yy[i]))
				no[kk[xx[i]]]=1;
			else merge(xx[i]+n,yy[i]),merge(xx[i],yy[i]+n);
		}
	}
	for(int i=1;i<=k;i++)
		t+=(no[i]==0);
	for(int i=1;i<=m;i++)
		if(kk[xx[i]]!=kk[yy[i]]){
			int a=kk[xx[i]],b=kk[yy[i]];
			if(no[a]||no[b])
				continue;
			if(a>b)
				swap(a,b);
			if(mp.count(make_pair(a,b))==0)
				mp[make_pair(a,b)]=++tot;
			q[mp[make_pair(a,b)]].push_back(i);
		}
	for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();it++){
		int a=it->first.first,b=it->first.second,c=it->second,r=top;
		for(int i=0;i<q[c].size();i++){
			int d=q[c][i],x=xx[d],y=yy[d];
			if(find(x)==find(y)){
				ans++;
				break;
			}
			merge(x+n,y),merge(x,y+n);
		}
		while(top!=r)
			f[rec[top]]=stk[top],top--;
	}
	printf("%lld\n",1ll*t*(t-1)/2-ans);
	return 0;
}