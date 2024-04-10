//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e4+5,mod=1e9+7,iv2=(mod+1)/2;
ll n,m;
int a[maxn];
int tot=1;
int t[30*maxn][2];
int siz[30*maxn];
int num[30*maxn][30];
ll read(){
	ll x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
int power(int x,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return ans;
}
void ins(int s){
	int x=1;
	for(int i=29;i>=0;i--){
		bool to=(s&(1<<i))>>i;
		if(!t[x][to])t[x][to]=++tot;
		for(int j=29;j>=0;j--)if(s&(1<<j))num[x][j]++;
		siz[x]++;
		x=t[x][to];
	}
	for(int j=29;j>=0;j--)if(s&(1<<j))num[x][j]++;
	siz[x]++;
	return ;
}
ll query1(int s,int v){
	int x=1;ll num=0;
	for(int i=29;i>=0;i--){
		bool to,c=(s&(1<<i))>>i,d=(v&(1<<i))>>i;
		to=c^d;
		if(d==0)num+=siz[t[x][to^1]];
		x=t[x][to];
		if(!x)break;
	}
	num+=siz[x];
	return num;
}
int query2(int s,int v){
	int x=1,sum=0;
	for(int i=29;i>=0;i--){
		bool to,c=(s&(1<<i))>>i,d=(v&(1<<i))>>i;
		to=c^d;
		if(d==0&&t[x][to^1]){
			int y=t[x][to^1];
			for(int j=29;j>=0;j--){
				bool h=(s&(1<<j))>>j;
				if(h==0)sum=add(sum+1ll*num[y][j]*(1<<j)%mod);
				else sum=add(sum+1ll*(siz[y]-num[y][j])*(1<<j)%mod);
			}
		}
		x=t[x][to];
		if(!x)break;
	}
	sum=add(sum+1ll*v*siz[x]%mod);
	return sum;
}
ll solve(int v){
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=query1(a[i],v);
	return sum;
}
int main(){
	n=read();m=2ll*read();
	for(int i=1;i<=n;i++)ins(a[i]=read());
	int l=0,r=(1<<30),mid;
	while(l+1<r){
		mid=l+((r-l)>>1);
		if(solve(mid)>=m)l=mid;
		else r=mid;
	}
	int sum=add(mod-1ll*(solve(l)-m)%mod*l%mod);
	for(int i=1;i<=n;i++)sum=add(sum+query2(a[i],l));
	printf("%d\n",(int)(1ll*sum*iv2%mod));
	return 0;
}