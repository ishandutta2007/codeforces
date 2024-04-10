#include<stdio.h>
#include<string.h>
int max(int x,int y){
	if (x>y){return x;}
	return y;
}
static char sb[105];
int main(){
	int t,n,i,j,k,one,zero,a,b;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		a=b=one=zero=0;
		scanf("%s",&sb);
		n=strlen(sb);
		for(j=0;j<=n-1;j++)
		{
			if(sb[j]=='1'){one++;}
			else{zero++;}
			if(sb[j]=='1'&sb[j+1]=='1'){a++;}
			if(sb[j]=='0'&sb[j+1]=='0'){b++;}
		}
		if(zero==0){printf("%s1\n",sb);continue;}
		if(one==0){printf("%s0\n",sb);continue;}
		zero+=a;one+=b;
		if(sb[0]=='1'){
		for(j=1;j<=max(one,zero);j++){printf("10");}printf("\n");continue;
        }
        if(sb[0]=='0'){
		for(j=1;j<=max(one,zero);j++){printf("01");}printf("\n");continue;
        }
		
	}
	
}