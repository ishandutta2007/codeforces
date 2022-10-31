#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[5050],f[5050][5050];
ll res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			memset(f[i],0,n*4+50);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<i;j++){
				f[i][j]=f[i][j-1];
				if(a[j]<a[i])f[i][j]++;
			}
		}
		for(i=1;i<=n;i++){
			k=0;
			for(j=n;j>i+1;j--){
				if(a[j]<a[i])k++;
				//printf("NMSL%d %d %d %d\n",i,j,k,f[j-1][i-1]);
				res+=k*f[j-1][i-1];
			}
		}
		cout<<res<<'\n';
	}
}