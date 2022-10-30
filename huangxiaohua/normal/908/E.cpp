#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
#define b(x) (1ll<<((x)-1))

int i,j,k,n,m,t;
ll s[5050][5050],b[5050],a[5050],res=1;
map<ll,int> mp;

int main(){
	s[0][0]=1;
	for(i=1;i<=5000;i++){
		for(j=1;j<=i;j++){
			s[i][j]=su(s[i-1][j-1],s[i-1][j]*j%M);
			b[i]=su(b[i],s[i][j]);
		}
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%1d",&k);
			if(k)a[j]+=b(i);
		}
	}
	for(j=1;j<=n;j++)mp[a[j]]++;
	for(auto [i,j]:mp)res=res*b[j]%M;
	printf("%lld",res);
}