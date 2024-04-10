#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000005
#define M 1000000007
int i,j,k,n,m,t;
ll res,f[2005000],l,r,r2=1,jc[1005000];
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main(){
	cin>>n;jc[0]=1;
	for(i=1;i<=1000000;i++)jc[i]=jc[i-1]*i%M;
	for(i=1;i<=n;i++){
		cin>>k;f[N-k+1]++;f[N+k+1]--;
	}
	for(i=-1000000;i<=1000000;i++){
		f[N+i]+=f[N+i-2];
		l=r+1;r+=f[N+i];
		res=su((l+r)*f[N+i]%M*su(M,i)%M,res);
		r2=r2*jc[f[N+i]]%M;
	}
	cout<<res*((M+1)/2)%M<<' '<<r2;
}