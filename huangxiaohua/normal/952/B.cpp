#include<bits/stdc++.h>
using namespace std;

int n,i,no;
char sb[666];

int main(){
	for(i=0;i<=9;i++){
		printf("%d\n",i);
		fflush(stdout);
		gets(sb);
		if(strcmp(sb,"cool")==0||strcmp(sb,"not bad")==0||strcmp(sb,"great")==0){puts("normal");return 0;}
		if(strcmp(sb,"terrible")==0||strcmp(sb,"worse")==0||strcmp(sb,"no way")==0){puts("grumpy");return 0;}
	}
	puts("NM$L");
}