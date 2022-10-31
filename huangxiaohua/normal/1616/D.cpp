#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll res,a[100500],su,f[100500][5];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		a[n+1]=-1e9;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		cin>>m;
		if(i==1){
			cout<<1<<'\n';
			continue;
		}
		for(i=1;i<=n;i++){
			a[i]-=m;
			memset(f[i],0,sizeof(f[i]));
		}
		f[1][0]=0;
		f[1][1]=1;
		for(i=2;i<=n;i++){
			f[i][0]=max({f[i][0],f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3]});
			f[i][1]=max({f[i][1],f[i-2][0]+1,f[i-2][1]+1,f[i-2][2]+1,f[i-2][3]+1});
			if((a[i]+a[i-1])>=0){
				if(i==2){
					f[i][2]=2;
				}
				else{
					f[i][2]=max({f[i][2],f[i-3][0]+2,f[i-3][1]+2,f[i-3][2]+2,f[i-3][3]+2,f[i-1][1]+1});
				}
			}
			if(i>=3&&(a[i]+a[i-1]+a[i-2])>=0&&(a[i]+a[i-1])>=0){
				f[i][3]=max({f[i][3],f[i-1][3]+1,f[i-1][2]+1});
			}
			//printf("NMSL%d %d %d %d %d\n",i,f[i][0],f[i][1],f[i][2],f[i][3]);
		}
		res=0;
		cout<<max({f[n][0],f[n][1],f[n][2],f[n][3]})<<'\n';
	}
}