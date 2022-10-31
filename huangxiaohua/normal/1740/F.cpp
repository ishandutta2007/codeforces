#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,a[2050],sb[2050],f[2050][2050],res;
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;a[k]++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			sb[i]+=min(i,a[j]);
		}
	}
	f[0][0]=1;
	for(t=n;t>=1;t--){
		for(i=1;i<=(n/t);i++){
			for(j=(i*t);j<=sb[i];j++){
				f[i][j]=su(f[i][j],f[i-1][j-t]);
			}
		}
	}
	for(i=1;i<=n;i++)res=su(res,f[i][n]);
	cout<<res;
}