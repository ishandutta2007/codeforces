#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x,y,a,b,i,j,k;

int main(){
	scanf("%d%d%d%d",&x,&y,&a,&b);
	printf("%d %d\n",a,b);
	for(i=y;i>=1;i--){
		if(i==b){continue;}
		printf("%d %d\n",a,i);
	}
	for(i=1,k=0;i<=x;i++){
		if(i==a){continue;}
		k++;
		if(k%2){
			for(j=1;j<=y;j++){
				printf("%d %d\n",i,j);
			}
		}
		else{
			for(j=y;j>=1;j--){
				printf("%d %d\n",i,j);
			}
		}
	}
}