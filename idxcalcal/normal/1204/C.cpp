#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
const int mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;} 
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=1e6+5;
int n,m;
char s[105];
int dis[105][105],a[N],q[N],top=0;
typedef long long ll;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i){
		scanf("%s",s+1);
		for(ri j=1;j<=n;++j){
			if(s[j]=='1')dis[i][j]=1;
			else dis[i][j]=0x3f3f3f3f;
		}		
	}
	for(ri k=1;k<=n;++k){
		for(ri i=1;i<=n;++i){
			if(dis[i][k]==0x3f3f3f3f)continue;
			for(ri j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	m=read();
	for(ri i=1;i<=m;++i){
		a[i]=read();
		while(top>1&&dis[q[top-1]][q[top]]+dis[q[top]][a[i]]==dis[q[top-1]][a[i]])--top;
		while(q[top]==a[i])++top;
		q[++top]=a[i];
	}
	cout<<top<<'\n';
	for(ri i=1;i<=top;++i)cout<<q[i]<<' ';
	return 0;
}