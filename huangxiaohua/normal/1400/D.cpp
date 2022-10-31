#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,t,a[3050],b[3050][3050],c[3050][3050];
ll res;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			c[n+1][i]=0;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				b[i][j]=b[i-1][j];
			}
			b[i][a[i]]++;
		}
		for(i=n;i>=1;i--){
			for(j=1;j<=n;j++){
				c[i][j]=c[i+1][j];
			}
			c[i][a[i]]++;
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				res+=b[i-1][a[j]]*c[j+1][a[i]];
			}
		}
		printf("%lld\n",res);
	}
}