#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t;
ll inv[100500],f[100500],g[100500],res=1;
vector<int> v[100500];
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main(){
	for(i=100000;i>=1;i--){
		for(j=i;j<=100000;j+=i)v[j].push_back(i);
	}
	inv[1]=1;for(int i=2;i<=100005;i++){inv[i]=(M-M/i)*inv[M%i]%M;}
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		for(auto j:v[i]){
			g[j]=su(g[j],n/j);
			for(auto k:v[j]){
				if(k!=j)g[k]=su(g[k],M-g[j]);
			}
		}
		f[i]=n;
		for(auto j:v[i]){
			if(j==i)continue;
			f[i]=su(f[i],g[j]*f[j]%M);
		}
		f[i]=f[i]*inv[n-g[i]]%M;
		res=su(res,inv[n]*f[i]%M);
		for(auto j:v[i])g[j]=0;
	}
	cout<<res;
}