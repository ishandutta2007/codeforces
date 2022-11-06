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
	#undef gc
}
typedef pair<int,int> pii;
typedef long long ll;
const int mod=998244353;
typedef vector<int> poly;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=305,S=4e5+5;
int vis[N][N];
char s[S];
struct Node{int x1,x2,y1,y2;};
vector<Node>a,b;
inline void fix(int x1,int y1,int x2,int y2,bool ff){
	++vis[x2][y2];
	if(ff)a.push_back((Node){x1,x2,y1,y2});
	else b.push_back((Node){x2,x1,y2,y1});
}
inline void update(int x,int y,int t,bool ff){
	if(t)fix(x,y,2,x!=2?y:(y==1?2:1),ff);
	else fix(x,y,1,x!=1?y:(y==1?2:1),ff);
}
int n,m;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	for(ri len,i=1;i<=n;++i)for(ri j=1;j<=m;++j){
		scanf("%s",s+1),len=strlen(s+1);
		for(ri k=len;k;--k)update(i,j,s[k]-'0',1);
	}
	for(ri x=1;x<3;++x)for(ri y=2;y<=m;++y){
		int t=vis[x][y];
		while(t--)fix(x,y,x,1,1);
		vis[x][y]=0;
	}
	for(ri len,i=1;i<=n;++i)for(ri j=1;j<=m;++j){
		scanf("%s",s+1),len=strlen(s+1);
		reverse(s+1,s+len+1);
		for(ri k=len;k;--k)update(i,j,s[k]-'0',0);
	}
	for(ri x=1;x<3;++x)for(ri y=2;y<=m;++y){
		int t=vis[x][y];
		while(t--)fix(x,y,x,1,0);
		vis[x][y]=0;
	}
	cout<<a.size()+b.size()<<'\n';
	for(ri i=0;i<a.size();++i)cout<<a[i].x1<<' '<<a[i].y1<<' '<<a[i].x2<<' '<<a[i].y2<<'\n';
	for(ri i=b.size()-1;~i;--i)cout<<b[i].x1<<' '<<b[i].y1<<' '<<b[i].x2<<' '<<b[i].y2<<'\n';
}