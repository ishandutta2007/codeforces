#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,l,r;
int f[200005][3];
int main(){
	scanf("%d%d%d",&n,&l,&r);
	f[0][0]=1;
	int m[3];
	m[0]=r/3-(l-1)/3;
	m[1]=(r+2)/3-(l+1)/3;
	m[2]=(r+1)/3-l/3;
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<3;++k){
				f[i][(j+k)%3]=(f[i][(j+k)%3]+1ll*f[i-1][j]*m[k])%mod;
			}
		}
	}
	printf("%d",f[n][0]);
	return 0;
}