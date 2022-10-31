#include<bits/stdc++.h>
using namespace std;

int i,j,t,n,sb[1055],ji,ou,jiou;
int main(){
    scanf("%d",&t);
    for(i=1;i<=t;i++){
		scanf("%d",&n);ji=ou=jiou=0;
		for(j=1;j<=n;j++){
			scanf("%d",&sb[j]);
		}
		sort(sb+1,sb+1+n);
		for(j=1;j<=n;j++){
			if(sb[j]%2==1){ji++;}
			if(sb[j]%2==0){ou++;}
			if(j>1&&sb[j]-sb[j-1]==1){jiou=1;}
		}
		if((ji%2==0&&ou%2==0)||jiou==1){puts("YES");}
		else{puts("NO");}
    }
    return 0;
}