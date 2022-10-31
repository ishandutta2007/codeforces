#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[55];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k==i){m++;}
			a[i]=k;
		}
		if(m==n){puts("0");continue;}
		if(a[1]==1||a[n]==n){puts("1");continue;}
		if(a[1]==n&&a[n]==1){puts("3");continue;
		}
		puts("2");
	}
}