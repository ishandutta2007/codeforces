#include<bits/stdc++.h>
using namespace std;

char sb[6666];
int n,i,t,j;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d\n",&n);
		for(i=1,j=1;i<=n;i++,j++){
			scanf("%c",&sb[j]);
			if(sb[j-1]=='('&&sb[j]==')'){
				j-=2;
			}
		}getchar();
		printf("%d\n",--j/2);
	}
}