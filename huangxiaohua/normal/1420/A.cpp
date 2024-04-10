#include<bits/stdc++.h>
using namespace std;
 
int i,n,a[100500],t,sb;

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);sb=1;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=2;i<=n;i++){
			if(a[i]>=a[i-1]){sb=0;break;}
		}
		if(!sb){puts("YES");}
		else{puts("NO");}
	}
}