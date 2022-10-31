#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],mx;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);mx=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			mx=max(mx,a[i]);
			if(a[i]==m){puts("1");goto aaa;}
		}
		printf("%d\n",max((m+mx-1)/mx,2));
		aaa:;
	}
}