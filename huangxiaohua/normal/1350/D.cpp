#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[100500],t,yes;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);yes=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==m){yes=1;}
		}
		if(!yes){puts("no");goto aaa;}
		if(n==1){puts("yes");continue;}
		for(i=2;i<=n;i++){
			if(a[i]>=m&&a[i-1]>=m){puts("yes");goto aaa;}
			if(i>2&&a[i]>=m&&a[i-2]>=m){puts("yes");goto aaa;}
		}
		puts("no");
		aaa:;
	}
}