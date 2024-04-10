#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,i,j,t,k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);k=0;
		for(i=1;i<=n;i++){
			scanf("%d",&j);k+=j;
		} 
		if(m==k){puts("YES");
		}else{puts("NO");
		}
	}
}