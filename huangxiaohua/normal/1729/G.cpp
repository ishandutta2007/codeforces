#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,n,m,t,f[505][505],g[505][505],a[505],lst,l,r;
string s1,s2;
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	for(i=1;i<=501;i++)g[i][i-1]=1;
	while(t--){
		cin>>s1>>s2;
		n=s1.size();m=s2.size();
		s1="$"+s1;
		for(i=1;i<=n;i++){
			a[i]=0;
			if(s1.substr(i,m)==s2)a[i]=1;
		}
		for(k=1;k<=n;k++){
			for(l=1;l+k-1<=n;l++){
				r=l+k-1;
				f[l][r]=99999;g[l][r]=1;lst=l-1;
				for(i=l;i+m-1<=r;i++){
					if(!a[i])continue;
					if(f[l][i-1]+f[i+m][r]+1<f[l][r]){
						f[l][r]=f[l][i-1]+f[i+m][r]+1;
						g[l][r]=1ll*g[l][i-1]*g[i+m][r]%M;lst=i+m-1;
					}
					else if(f[l][i-1]+f[i+m][r]+1==f[l][r]&&i<=lst){
						g[l][r]=su(g[l][r],1ll*g[l][i-1]*g[i+m][r]%M);
					}
				}
				if(f[l][r]==99999)f[l][r]=0;
				//printf("NMSL%d %d %d\n",l,r,g[l][r]);
			}
		}
		cout<<f[1][n]<<' '<<g[1][n]<<'\n';
	}
}