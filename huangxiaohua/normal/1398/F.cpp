#include <stdio.h>
int i,j,k,n,m,t,res,x,y,s0[1005000],s1[1005000];
char c[1005000];
int main(){
	scanf("%d%s",&n,c+1);
	for(i=1;i<=n;i++){
		s0[i]=(c[i]=='0')?i:s0[i-1];
		s1[i]=(c[i]=='1')?i:s1[i-1];
	}
	for(i=1;i<=n;i++){
		for(res=0,j=1;j+i-1<=n;j+=i){
			x=s0[j+i-1];y=s1[j+i-1];
			k=((x<y)?x:y);
			if(k<j){res++;}
			else{j=k-i+1;}
		}
		printf("%d ",res);
	}
}