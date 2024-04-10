#include<bits/stdc++.h>
using namespace std;

int i,t,n;
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=30){puts("NO");continue;}
		if(n==36){printf("YES\n%d %d %d %d\n",6,10,15,5);continue;}
		if(n==40){printf("YES\n%d %d %d %d\n",6,10,15,9);continue;}
		if(n==44){printf("YES\n%d %d %d %d\n",6,10,15,13);continue;}
		printf("YES\n%d %d %d %d\n",6,10,14,n-6-10-14);
	}
}