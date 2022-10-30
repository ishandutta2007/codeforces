#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,sb[5055],a,b,c,d;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);a=b=c=d=0;
		for(i=1;i<=n;i++){
			scanf("%d",&sb[i]);
			if(!a){a=sb[i];c=i;continue;}
			if(sb[i]!=a){b=sb[i];d=i;}
		}
		if(!b){puts("NO");continue;}
		puts("YES");
		for(i=2;i<=n;i++){
			if(sb[i]==a){printf("%d %d\n",i,d);}
			else{printf("%d %d\n",i,1);}
		}
	}
}