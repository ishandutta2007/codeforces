#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1e5+9;
const int lim=1e18;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
int mu[N],p[N],vis[N],len;
void init(int n=100){
	mu[1]=1;
	For(i,2,n){
		if(!vis[i])p[++len]=i,mu[i]=-1;
		for(int j=1;j<=len&&p[j]*i<=n;j++){
			vis[p[j]*i]=1;
			if(i%p[j]==0)break;
			mu[p[j]*i]=-mu[i];
		}
	}
}
int inv(int x,int base){
	int res=1;
	while(base){
		if(base&1)res=res*x;
		x=x*x;
		base>>=1;
	}return res;
}
bool check(int n,int m,int k){
	if(log10(n)*m>18)return false;
	return inv(n,m)<=k;
}
int mx[N],op;
int solve(int n,int m){
	if(m==1)return n;
	int l=1,r=op?mx[m]:n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,m,n))l=mid+1;
		else r=mid-1;
	}return (l-1)-1;
}
int sta[N],a[N],b[N];
map<int,int>mp;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
//	freopen("1.out","w",stdout);
	init();
	int T=read();rep(i,T)a[i]=b[i]=read();
	sort(b+1,b+1+T);
	rep(i,T){
		For(j,4,59)while(check(sta[j]+1,j,b[i]))sta[j]++;
		rep(j,3)sta[j]=solve(b[i],j);
		int ans=0;
		rep(i,60)ans+=mu[i]*sta[i];
		mp[b[i]]=ans;
	}
	rep(i,T)printf("%lld\n",mp[a[i]]-1);
	return 0;
}