#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define N 720720
int i,j,k,n,m,t,g;
ll sb,x,y,tot,res,lst,p[N+5],t1;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main() {
	cin>>n>>lst>>x>>y>>m>>sb;
	for(i=1;i<=n;i++){
		p[lst%N]++;res=su(res,(lst/N)*N);
		lst=(lst*x+y)%sb;
	}
	res=res*ksm(n,m-1)%M*m%M;
	for(i=1;i<=m;i++){
		for(tot=0,j=1;j<=N;j++){
			tot+=p[j]*j%M;t1=p[j];
			p[j]=p[j]*(n-1)%M;
			p[j-j%i]=su(p[j-j%i],t1);
		}//
		res=su(res,tot%M*ksm(n,m-i)%M);
	}
	cout<<res;
}