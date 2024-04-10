// Hydro submission #62c58c438672efa577befa78@1657113667611
#include<bits/stdc++.h>
#define ll long long
#define Max(a,b) ((a)<(b) and ((a)=(b)))
#define Min(a,b) ((a)>(b) and ((a)=(b)))
#define Add(a,b) (((x)+=(y))>=mod and ((x)-=mod))
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define PF(i,a,b) for(int i=(a);i>=(b);--i)
#define For(i,x) for(int i=head[(x)];i;i=net[(i)])
using namespace std;
bool beginning;
inline int read();
const int N=3e3+5;
int n;
ll a[N],dp[N][N],Mi[N][N],b[N];
bool ending;
int main() {
	cerr<<1.0*(&beginning-&ending)/1024/1024<<"MB\n--------\n";
	n=read();
	int cnt=n;
	F(i,1,n)a[i]=read()-i,b[i]=a[i];
	
	sort(b+1,b+cnt+1);
	
	cnt=unique(b+1,b+cnt+1)-b-1;

	F(i,1,n)a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	
	memset(Mi,0x3f,sizeof(Mi));
	memset(dp,0x3f,sizeof(dp));
	
	F(i,0,n)dp[0][i]=Mi[0][i]=0;
	
	F(i,1,n) {
		F(j,1,cnt) {
			Min(dp[i][j],Mi[i-1][j]+abs(b[a[i]]-b[j]));
			Mi[i][j]=min(Mi[i][j-1],dp[i][j]);
		}
	}
	
	printf("%lld\n",Mi[n][cnt]);
}
inline int read() {
	int x=0;
	bool f=1;
	char c=getchar();
	while(!isdigit(c))f=c^45,c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}