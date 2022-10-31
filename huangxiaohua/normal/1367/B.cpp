#include <bits/stdc++.h>
using namespace std;
 
int n,t,i,sb,ji,ou;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ji=ou=0;
		for(i=1;i<=n;i++){
			scanf("%d",&sb);
			if((sb%2)^(i%2)==0&&i%2==1){ji++;}
			if((sb%2)^(i%2)==0&&i%2==0){ou++;}
		}
		(ji==ou)?printf("%d\n",ji):puts("-1");
	}
}