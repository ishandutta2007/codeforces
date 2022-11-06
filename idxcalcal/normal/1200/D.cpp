#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=2005;
char s[N][N];
int n,k,a1[N],a2[N],b1[N],b2[N],cnt1[N],cnt2[N];
int ss[N][N];
inline bool check(int x,int y,int a,int b){
	if(x==-1)return 1;
	return a<=x&&b>=y;
}
inline int q1(int a,int b){return cnt1[a-1]+cnt1[n]-cnt1[b];}
inline int q2(int a,int b){return cnt2[a-1]+cnt2[n]-cnt2[b];}
signed main(){
	n=read(),k=read();
	for(ri i=1;i<=n;++i)scanf("%s",s[i]+1),a1[i]=b1[i]=a2[i]=b2[i]=-1;
	for(ri i=1;i<=n;++i){
		for(ri j=1;j<=n;++j){
			if(s[i][j]=='B'){
				~a1[i]?a1[i]=min(a1[i],j):a1[i]=j;
				~b1[j]?b1[j]=min(b1[j],i):b1[j]=i;
				~a2[i]?a2[i]=max(a2[i],j):a2[i]=j;
				~b2[j]?b2[j]=max(b2[j],i):b2[j]=i;
			}
		}
	}
	for(ri i=1;i<=n;++i){
		if(a1[i]==-1){
			++ss[1][1];
			continue;
		}
		if(a2[i]-a1[i]+1>k)continue;
		int x1=max(1,i-k+1),x2=i,y1=max(1,a2[i]-k+1),y2=a1[i];
		++ss[x1][y1],++ss[x2+1][y2+1],--ss[x1][y2+1],--ss[x2+1][y1];
	}
	for(ri i=1;i<=n;++i){
		if(b1[i]==-1){
			++ss[1][1];
			continue;
		}
		if(b2[i]-b1[i]+1>k)continue;
		int y1=max(1,i-k+1),y2=i,x1=max(1,b2[i]-k+1),x2=b1[i];
		++ss[x1][y1],++ss[x2+1][y2+1],--ss[x1][y2+1],--ss[x2+1][y1];
	}
	int ans=0;
	for(ri i=1;i<=n-k+1;++i)for(ri j=1;j<=n-k+1;++j)ss[i][j]+=ss[i-1][j]+ss[i][j-1]-ss[i-1][j-1],ans=max(ans,ss[i][j]);
	cout<<ans;
	return 0;
}