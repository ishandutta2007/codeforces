#include<bits/stdc++.h>
using namespace std;

int n2,n3,t,i,sb;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&sb);n2=n3=0;
		while(sb%2==0){sb/=2;n2++;}
		while(sb%3==0){sb/=3;n3++;}
		if(sb!=1||n2>n3){puts("-1");}
		else{printf("%d\n",n3*2-n2);}
	}
}