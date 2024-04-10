#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define M 1000000007

int i,j,k,n,t,m,f[200500][32],b[32],x,y,w,no[32];
ll sb,res;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		sb=1;
		res=0;
		for(i=1;i<n;i++){
			sb=sb*2%M;
		}
		
		memset(b,0,sizeof(b));
		memset(no,0,sizeof(no));
		
		for(i=1;i<=n;i++){
			memset(f[i],0,sizeof(f[i]));
		}
		
		for(i=1;i<=m;i++){
			cin>>x>>y>>w;
			for(j=1;j<=30;j++){
				if(w&b(j)){
					continue;
				}
				f[x][j]++;
				f[y+1][j]--;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=30;j++){
				f[i][j]+=f[i-1][j];
				if(f[i][j]){
					no[j]++;
				}
			}
		}
		for(i=1;i<=30;i++){
			if(n!=no[i]){
				res+=(1ll<<(i-1))*sb%M;
			}
		}
		cout<<res%M<<'\n';
	}
}