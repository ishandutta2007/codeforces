#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define db double
using namespace std;
const int N=2e5+5;
int n,x,y,l,w[N],wz;
int z,si[N],sz[N],all;
struct edge{int y;db l;};
vector<edge>e[N];
bool ban[N];
db ans,g[N];
void get2(int x){
	++all;ban[x]=1;
	for(auto i:e[x])if(!ban[i.y])get2(i.y);
	ban[x]=0;
}
void get(int x){
	ban[x]=1;si[x]=1;sz[x]=0;
	for(auto i:e[x])if(!ban[i.y])get(i.y),si[x]+=si[i.y],sz[x]=max(sz[x],si[i.y]);
	sz[x]=max(sz[x],all-si[x]);
	ban[x]=0;
	if(sz[x]<sz[z])z=x;
}
db dfs(int x,db len,int no){
	db s=sqrt(len)*w[x];
	for(auto i:e[x])if(i.y!=no)
		s+=dfs(i.y,len+i.l,x);
	return s;
}
db dfs1(int x,db len,int no){
	db s=pow(len,1.5)*w[x];
	for(auto i:e[x])if(i.y!=no)
		s+=dfs1(i.y,len+i.l,x);
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fo(i,1,n)cin>>w[i];
	fo(i,2,n){
		cin>>x>>y>>l;
		e[x].push_back((edge){y,l});
		e[y].push_back((edge){x,l});
	}
	x=1;sz[0]=n+1;
	for(;;){
		all=0;get2(x);z=0;get(x);x=z;
		ban[x]=1;
		db all2=0;
		for(auto i:e[x]){
			g[i.y]=dfs(i.y,i.l,x);
			all2+=g[i.y];
		}
		bool can=0;
		for(auto i:e[x])if(all2-g[i.y]*2<-1e-9){
			if(ban[i.y]){
				ans=dfs1(x,0,0);
				db ans2=dfs1(i.y,0,0);
				if(ans<ans2)wz=x;
				else wz=i.y,ans=ans2;
				printf("%d %.8lf\n",wz,ans);
				return 0;
			}
			x=i.y;
			can=1;
			break;
		}
		if(!can){
			printf("%d %.8lf\n",x,dfs1(x,0,0));
			return 0;
		}
	}
}