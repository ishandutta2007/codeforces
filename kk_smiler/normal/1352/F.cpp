#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,n0,n1,n2;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n0,&n1,&n2);
		int s=(n0|n1)?0:1;
		printf("%c",s+'0');
		while(n0+n1+n2){
			if(s==0) while(n0) n0--,printf("0");
			if(s==1) while(n2) n2--,printf("1");
			if(n1) n1--,printf("%c",s^1+'0'),s^=1;
		}
		printf("\n");
	}
}