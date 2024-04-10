#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[505][505],it,l,r,mn,tmp,res;
char s[505];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>s+1;
	memset(f,1,sizeof(f));
	for(i=1;i<=n;i++){
		s[i]-='a'-1;
		f[i][i]=1;
	}
	for(i=2;i<=n;i++){
		for(l=1;l+i-1<=n;l++){
			r=l+i-1;
			for(j=l;j<r;j++){
				f[l][r]=min(f[l][r],f[l][j]+f[j+1][r]);
			}
			f[l][r]-=(s[l]==s[r]);
		}
	}
	cout<<f[1][n];
}