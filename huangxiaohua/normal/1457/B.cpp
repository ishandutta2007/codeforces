#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,l[100500],a[100500],f[100500],res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==a[i-1]){l[i]=l[i-1];}
			else{l[i]=i;}
		}
		res=1145141919;
		for(i=1;i<=100;i++){
			for(j=1;j<=n;j++){
				if(a[j]==i){
					f[j]=f[l[j]-1];
				}
				else{
					f[j]=f[max(0,j-m)]+1;
				}
			}
			res=min(res,f[n]);
		}
		printf("%d\n",res);
	}
}