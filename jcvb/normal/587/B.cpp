#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
		int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
			if(c=='-')sg=-1,x=0;else x=c-'0';
				while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
					x*=sg;
}
void gn(ll &x){
		int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
			if(c=='-')sg=-1,x=0;else x=c-'0';
				while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
					x*=sg;
}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;
int n,k;
ll l;
struct node{
	int x;
	bool bo;
}a[1111111];
int cmp(const node&a,const node&b){
	return a.x<b.x;
}
int f[1111111];
int g[1111111];
int an[1111111];

int main()
{
	gn(n);gn(l);gn(k);
	for (int i=0;i<n;i++)gn(a[i].x);
	int t=l%n;
	for (int i=0;i<t;i++)a[i].bo=1;
	sort(a,a+n,cmp);
	for (int i=0;i<n;i++)f[i]=1;
	an[1]=n;
	for (int i=2;i<=k;i++){
		int su=0;
		int cur=n-1;
		for (int j=n-1;j>=0;j--){
			while(cur>=0 && a[cur].x>=a[j].x){
				su=(su+f[cur])%mo;
				cur--;
			}
			g[j]=su;
			an[i]=(an[i]+g[j])%mo;
		}
		for (int j=0;j<=n-1;j++)f[j]=g[j];
	}
	ll q=l/n;
	int ans=0;
	for (int i=1;i<=k;i++){
		ans=(0ll+ans+1ll*(max(0ll,q-i+1)%mo)*an[i])%mo;
	}

	an[1]=0;
	for (int i=0;i<n;i++)an[1]+=(f[i]=a[i].bo);
	for (int i=2;i<=k;i++){
		an[i]=0;
		int su=0;
		int cur=n-1;
		for (int j=n-1;j>=0;j--){
			while(cur>=0 && a[cur].x>=a[j].x){
				su=(su+f[cur])%mo;
				cur--;
			}
			g[j]=su;
			an[i]=(an[i]+g[j])%mo;
		}
		for (int j=0;j<=n-1;j++)f[j]=g[j];
	}

	for (int i=1;i<=k && i<=q+1;i++){
		ans=(ans+an[i])%mo;
	}
	printf("%d\n",ans);
	return 0;
}