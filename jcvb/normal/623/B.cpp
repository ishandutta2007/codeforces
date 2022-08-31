#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
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
int mo=1000000007;
ll inf=1e18;
db eps=1e-6;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int n,a,b;
int arr[1111111];



ll mi=inf;


int ned[1111];int ntot=0;

void fac(int x){
	for (int i=2;1ll*i*i<=x;i++)if(x%i==0){
		ned[++ntot]=i;
		while(x%i==0)x/=i;
	}
	if(x>1)ned[++ntot]=x;
}

int bo[1111111];
ll f[1111111][3];
inline void upd(ll &x,ll b){
	x=min(x,b);
}
void dp(){
	if(bo[1]==-1)return;
	f[1][0]=bo[1]*b;
	f[1][1]=f[1][2]=inf;
	for (int i=1;i<=n;i++){
		f[i+1][0]=f[i+1][1]=f[i+1][2]=inf;

		if(bo[i+1]!=-1){
			upd(f[i+1][0],f[i][0]+bo[i+1]*b);
			upd(f[i+1][2],min(f[i][1],f[i][2])+bo[i+1]*b);
		}
		upd(f[i+1][1],f[i][0]+a);
		upd(f[i+1][1],f[i][1]+a);
	}
	mi=min(mi,f[n+1][0]);
	mi=min(mi,f[n+1][2]);
}
void work(ll x){
	for (int i=1;i<=n;i++){
		int t=arr[i]%x;
		if(t==0)bo[i]=0;
		else if(t==1 || t==x-1)bo[i]=1;
		else bo[i]=-1;
	}
	dp();

}
int main()
{
	gn(n);gn(a);gn(b);
	for (int i=1;i<=n;i++)gn(arr[i]);
	fac(arr[1]-1);
	fac(arr[1]);
	fac(arr[1]+1);
	for (int i=1;i<=ntot;i++)work(ned[i]);
	for (int i=1;i<=n-i+1;i++)swap(arr[i],arr[n-i+1]);
	ntot=0;
	fac(arr[1]-1);
	fac(arr[1]);
	fac(arr[1]+1);
	for (int i=1;i<=ntot;i++)work(ned[i]);
	cout<<mi<<endl;
	return 0;
}