#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[300050],m,l,r;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&m);
		l=0;r=k;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(a[i]+l>m){puts("No");goto aaa;}
			if(a[i]+k<=m){l=0;r=k;}
			r=min(r,m-a[i]);
			if(!r){l++;}else{r--;}
		}
		puts("Yes");
		aaa:;
	}
}