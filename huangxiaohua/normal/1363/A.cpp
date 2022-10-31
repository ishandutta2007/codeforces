#include<bits/stdc++.h>
using namespace std;
int i,n,sb,ji,m,j,k;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&m,&k);ji=0;
		for(j=1;j<=m;j++){
			scanf("%d",&sb);
			if(sb%2==1){ji++;}
		}
		if((m==k&&ji%2==1)||(m!=k&&ji>0&&ji!=m)||ji==m&&k%2==1){puts("YES\n");}
		else{puts("NO\n");}
	}
}