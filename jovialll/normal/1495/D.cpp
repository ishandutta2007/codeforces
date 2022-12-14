#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define N 405
#define ls (k<<1)
#define rs (k<<1|1)
#define pb push_back
#define yes puts("Yes\n");
#define no puts("No\n");
#define mod 998244353

//#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
//char buf[1<<21],*p1,*p2,ch;
//int ret;
//inline int re() {
//	ret=0;
//	ch=getc();
//	while(!isdigit(ch)){
//		ch=getc();
//	}
//	while(isdigit(ch)){
//		ret=(ret<<1)+(ret<<3)+(ch^48);
//		ch=getc();
//	}
//	return ret;
//}
inline int re(){int x;cin>>x;return x;} 
inline ll ksm(ll x,ll y){ll r=1;for(;y;y>>=1,x=x*x%mod)if(y&1)r=r*x%mod;return r;}
int T,n,i,j,k,m,x,y,a[N],d[N][N],c[N][N],rd[N],vv[N];
ll ans[N][N];
vector<int>son[N];queue<int>q;
int main(){
	cin>>n>>m;
	for(i=1;i<=m;++i)cin>>x>>y,son[x].pb(y),son[y].pb(x);
	for(i=1;i<=n;++i){
		q.push(i);memset(d[i],-1,sizeof(d[i]));memset(rd,0,sizeof(rd));d[i][i]=0;rd[i]=0;
		while(q.size()){
			x=q.front();q.pop();rd[x]=(rd[x]>1)+1;
			for(j=0;j<son[x].size();++j){
				if(!~d[i][T=son[x][j]])d[i][T]=d[i][x]+1,q.push(T);
				if(d[i][T]==d[i][x]+1)rd[T]+=rd[x];
			}
		}
		for(j=1;j<=n;++j)if(rd[j]>1)c[i][j]=1;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(c[i][j])continue;
			memset(rd,0,sizeof(rd));
			for(x=1;x<=n;++x)
				if(d[i][x]+d[x][j]==d[i][j])
					q.push(x),rd[x]=1;
			while(q.size()){
				x=q.front();q.pop();
				for(k=0;k<son[x].size();++k){
					T=son[x][k];
					if(d[x][i]+1==d[i][T]&&d[j][x]+1==d[j][T]){
						if(!rd[T])q.push(T);
						++rd[T];
					}
				}
			}
			ans[i][j]=1;
			for(k=1;k<=n;++k)ans[i][j]=ans[i][j]*rd[k]%mod;
		}
	}
	for(i=1;i<=n;cout<<"\n",++i)for(j=1;j<=n;++j)cout<<ans[i][j]<<" ";
}