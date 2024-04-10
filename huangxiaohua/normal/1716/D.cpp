#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
int i,j,k,n,m,t,tot;
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
int res[200500],f[205000],g[200500],p;

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	f[0]=1;
	for(i=m;;i++){
		tot+=i;
		if(tot>n)break;
		for(j=0;j<i;j++){
			p=0;
			for(k=j;k<=n;k+=i){
				g[k]=p;
				p=su(p,f[k]);
			}
		}
		memcpy(f,g,sizeof(g));
		memset(g,0,sizeof(g));
		for(j=1;j<=n;j++){
			//cout<<f[j]<<' ';
			res[j]=su(res[j],f[j]);
		}
		//cout<<endl;
	}
	for(i=1;i<=n;i++)cout<<res[i]<<' ';
}