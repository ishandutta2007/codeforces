#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n;
ll f[405][2005];
void su(ll &a,ll b){a=(a+b)%M;}

int main(){
	cin>>n;
	f[1][1]=1;
	for(i=1;i<=n;i++){
		f[i][0]=1;
		for(j=0;j<=n+5;j++){
			for(k=0;k<=n+5;k++){
				su(f[i+1][j+k+1],f[i][j]*f[i][k]);
				su(f[i+1][j+k],f[i][j]*f[i][k]%M*(j+j+k+k+1)%M);
				su(f[i+1][j+k-1],f[i][j]*f[i][k]%M*(j+k)%M*(j+k-1)%M);
			}
		}
		puts("");
	}
	cout<<f[n][1];
}