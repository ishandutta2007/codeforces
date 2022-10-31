#include <bits/stdc++.h>
using namespace std;

int n,i,t,j,res,sb[150],k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res=0;
		memset(sb,0,sizeof(sb));
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			sb[k]++;
		}
		for(i=0;i<=105;i++){
			if(sb[i]){sb[i]--;
			}
			else{res+=i;break;
			}
		}
		for(i=0;i<=105;i++){
			if(sb[i]){sb[i]--;
			}
			else{res+=i;break;
			}
		}
		printf("%d\n",res);
	}
}