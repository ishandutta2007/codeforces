#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,wcnmlgb[105],res,k,tmp,t;

int main(){
	scanf("%d",&t);
	wcnmlgb[0]=-1;
	while(t--){
		scanf("%d%d",&n,&k);tmp=0;
		for(i=1;i<=n;i++){
			scanf("%d",&wcnmlgb[i]);
			if(wcnmlgb[i]!=wcnmlgb[i-1]){tmp++;}
		}
		if(k==1){
			if(tmp==1){puts("1");
			}else{puts("-1");
			}
		}
		else{
			printf("%d\n",max(1+(tmp-k)/(k-1)+(((tmp-k)%(k-1))>0),1));
		}
	}
}