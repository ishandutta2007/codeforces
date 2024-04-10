#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[105];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);k=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			k+=a[i];
		}
		if(k==m){puts("NO");continue;}
		k=0;puts("YES");
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[j]&&a[j]+k!=m){
					printf("%d ",a[j]);k+=a[j];a[j]=0;break;
				}
			}
		}
		puts("");
	}
}