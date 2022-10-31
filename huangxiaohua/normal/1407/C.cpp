#include<bits/stdc++.h>
using namespace std;
 
int res[10050],n,i,j,a=1,b=2,used[10050],x,y;
 
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("! 1");return 0;
	}
	for(i=1;i<=n-1;i++){
		printf("? %d %d\n",a,b);
		fflush(stdout);
		scanf("%d",&x);
		printf("? %d %d\n",b,a);
		fflush(stdout);
		scanf("%d",&y);
		if(x>y){
			res[a]=x;used[a]=1;
			for(;;a++){
				if(!used[a]&&a!=b){break;}
			}
		}
		else{
			res[b]=y;used[b]=1;
			for(;;b++){
				if(!used[b]&&a!=b){break;}
			}
		}
	}printf("! ");
	for(i=1;i<=n;i++){
		if(used[i]){
			printf("%d ",res[i]);
		}
		else{
			printf("%d ",n);
		}
	}
}