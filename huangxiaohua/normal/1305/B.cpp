#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

int i,j,n,res[1050],rn;
char sb[1050];

int main(){
	gets(sb+1);
	n=strlen(sb+1);
	for(i=1,j=n;i<j;){
		if(sb[i]==')'){i++;continue;}
		if(sb[j]=='('){j--;continue;}
		rn+=2;res[rn-1]=i;res[rn]=j;i++;j--;
	}
	if(rn==0){puts("0");return 0;}
	sort(res+1,res+rn+1);
	printf("1\n%d\n",rn);
	for(i=1;i<=rn;i++){
		printf("%d ",res[i]);
	}
}