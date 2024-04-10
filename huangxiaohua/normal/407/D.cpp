#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,r,pos[405][160005],a[405][405],f[405][405],res;
void chk(int &x,int y){x=max(x,y);}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			chk(f[j][j],pos[j][a[i][j]]);
			pos[j][a[i][j]]=i;
			chk(res,i-f[j][j]);
		}
		for(j=2;j<=m;j++){
			for(l=1;l+j-1<=m;l++){
				r=l+j-1;
				f[l][r]=max({f[l][r],f[l+1][r],f[l][r-1],pos[l][a[i][r]],pos[r][a[i][l]]});
				chk(res,j*(i-f[l][r]));
			}
		}
	}
	cout<<res;
}