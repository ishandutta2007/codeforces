#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const int inf=1e8;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,K;
char s[30];
int a[30],b[30],p[30],bin[30];
int aa[30],bb[30];
int cnt[(1<<20)+10];
int dp[2][(1<<20)+10];
int getnum(int *c){
	int re=0;
	for(int i=K;i>=1;--i) re=re<<1|c[i];
	return re;
}
void umin(int &x,int y){if(x>y)x=y;}
void umax(int &x,int y){if(x<y)x=y;}
int main(){
	for(int i=0;i<=(1<<19);++i){
		cnt[i<<1]=cnt[i];
		cnt[i<<1|1]=cnt[i]+1;
	}
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s",s+1);
	for(int i=1;i<=K;++i) a[i]=s[i]-'0';
	scanf("%s",s+1);
	for(int i=1;i<=K;++i) b[i]=s[i]-'0';
	for(int i=0;i<=(1<<20);++i) dp[0][i]=inf;
	for(int i=0;i<=(1<<20);++i) dp[1][i]=-inf;
	umin(dp[0][getnum(a)],0);
	umax(dp[1][getnum(b)],0);
	for(int i=1;i<=K;++i) p[i]=i;
	int l,r;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&l,&r);
		swap(p[l],p[r]);
		for(int j=1;j<=K;++j){
			aa[p[j]]=a[j];
			bb[p[j]]=b[j];
		}
		//for(int j=1;j<=K;++j) cout<<aa[j]<<" ";puts("");
		//for(int j=1;j<=K;++j) cout<<bb[j]<<" ";puts("");
		umin(dp[0][getnum(aa)],i);
		umax(dp[1][getnum(bb)],i);
	}
	for(int i=(1<<K)-1;i>0;--i){
		for(int j=0;j<K;++j){
			if(i&(1<<j)){
				umin(dp[0][i-(1<<j)],dp[0][i]);
				umax(dp[1][i-(1<<j)],dp[1][i]);
			}
		}
	}
	int ans=-1;
	for(int i=0;i<(1<<K);++i){
		if(cnt[i]>ans&&dp[1][i]-dp[0][i]>=m){
			ans=cnt[i];
			l=dp[0][i]+1;
			r=dp[1][i];
		}
	}
	ans=K+ans+ans;
	for(int i=1;i<=K;++i) ans=ans-a[i]-b[i];
	cout<<ans<<endl<<l<<" "<<r<<endl;
	return 0;
}