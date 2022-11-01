#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define li(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define pb push_back
using namespace std;
const int N=2e5+5;
int n,m,x,y;
int la[N],ne[N*2],to[N*2],js;
int df[N*2],lo[N],z[N],ds,zs,be[N],tp[N],bs;
int vi[N];
struct graph{
	vector<int>d;
	map<int,int>b;
	vector<vector<int>>e;
	int es;
	void work(){
		fo(i,0,d.size()-1)b[d[i]]=i;
		e.resize(d.size());
	}
	void link(int x,int y){
		x=b[x];y=b[y];++es;
		e[x].pb(y);e[y].pb(x);
	}
	bool get_c(int x){
		if(bs&&!x)return 1;
		df[++bs]=x;vi[x]=1;
		for(int i:e[x])
			if((!vi[i]||!i)&&(bs==1||i!=df[bs-1])&&get_c(i))
				return 1;
		--bs;
		return 0;
	}
	bool get_c2(int x,int no){
		if(js&&vi[x]>0)return lo[++js]=x,1;
		if(!vi[x])vi[x]=-1;
		lo[++js]=x;
		for(int i:e[x])if((!vi[i]||vi[i]>0&&i!=no&&(vi[x]<0||min(abs(vi[x]-vi[i]),abs(vi[x]+bs-vi[i]))>1))&&(js==1||i!=lo[js-1])&&get_c2(i,no))return 1;
		--js;
		return 0;
	}
	void go(){
		bs=0;
		get_c(0);
		fo(i,0,d.size()-1)vi[i]=0;
		fo(i,1,bs)vi[df[i]]=i,df[i+bs]=df[i];
		fo(i,1,bs)if(e[df[i]].size()>2){
			js=0;
			get_c2(df[i],df[i]);
			cout<<"YES\n";
			cout<<js<<" ";
			fo(j,1,js)cout<<d[lo[j]]<<" ";
			int wz=vi[lo[js]];
			cout<<endl<<wz-i+1<<" ";
			fo(j,i,vi[lo[js]])cout<<d[df[j]]<<" ";
			cout<<endl<<i+bs-wz+1<<" ";
			fd(j,wz,i+bs)cout<<d[df[j]]<<" ";
			return;
		}
	}
}g[N];
void tar(int x,int j){
	df[x]=lo[x]=++ds;z[++zs]=x;int y;
	for(int i=la[x];i;i=ne[i])if(df[y=to[i]]){
		if(i!=j)lo[x]=min(lo[x],df[y]);
	}else{
		tar(y,i^1);lo[x]=min(lo[x],lo[y]);
		if(df[x]<lo[y])--zs,be[y]=++bs;
		if(df[x]==lo[y]){
			++bs;
			g[bs].d.pb(x);
			for(;z[zs+1]!=y;--zs)tp[z[zs]]=x,be[z[zs]]=bs,g[bs].d.pb(z[zs]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;js=1;
	fo(i,1,m)cin>>x>>y,li(x,y),li(y,x);
	fo(i,1,n)if(!df[i])tar(i,0),zs=0,be[i]=++bs;
	fo(i,1,bs)g[i].work();
	fo(i,1,n)for(int j=la[i];j;j=ne[j])if((y=to[j])>i)
		if(be[i]==be[y]||tp[i]==y)g[be[i]].link(i,y);else
		if(tp[y]==i)g[be[y]].link(i,y);
	fo(i,1,bs)if(g[i].es!=g[i].d.size()){g[i].go();return 0;}
	cout<<"NO";
}