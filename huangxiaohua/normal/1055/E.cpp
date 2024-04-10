#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,a[1550],l[1550],res,L,R,md,li;
int p[1550],f[1550][1550];

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m>>sb>>li;
	res=2e9;
	for(i=1;i<=n;i++){
		cin>>a[i];
		l[i]=n+5;
	}
	for(i=1;i<=m;i++){
		cin>>j>>k;
		//r[j]=max(r[j],k);
		//l[k]=min(l[k],j);
		for(t=j;t<=k;t++){
			l[t]=min(l[t],j);
		}
	}
	L=1;R=1e9;
	while(L<=R){
		md=(L+R)/2;
		for(i=1;i<=n;i++){
			p[i]=p[i-1]+(a[i]<=md);
		}
		for(i=n+1;i<=n+10;i++){
			p[i]=p[i-1];
		}
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			for(j=1;j<=sb;j++){
				f[i][j]=max(f[i-1][j],f[l[i]-1][j-1]+p[i]-p[l[i]-1]);
			}
		}
		if(f[n][sb]>=li){
			R=md-1;res=min(res,md);
		}
		else L=md+1;
	}
	if(res>1e9){
		cout<<-1;
	}
	else cout<<res;
}