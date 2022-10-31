#include<bits/stdc++.h>
using namespace std;

int i,j,n,k,t,mx,a[1050][1050],b[1050][1050],dp2[1050][1050],dp5[1050][1050],op2[1050][1050],op5[1050][1050],sb1,sb2;

void ans0(){
	puts("1");
	for(i=1;i<sb1;i++){printf("D");}
	for(j=1;j<n;j++){printf("R");}
	for(i=1;i<=n-sb1;i++){printf("D");}
}

void ans2(){
	printf("%d\n",dp2[n][n]);
	int s[2050],m=0;i=j=n;
	while(i+j>2){
		if(op2[i][j]){s[++m]=1;j--;}
		else{s[++m]=0;i--;}
	}
	while(m){printf("%c",s[m--]?'R':'D');}
}

void ans5(){
	printf("%d\n",dp5[n][n]);
	int s[2050],m=0;i=j=n;
	while(i+j>2){
		if(op5[i][j]){s[++m]=1;j--;}
		else{s[++m]=0;i--;}
	}
	while(m){printf("%c",s[m--]?'R':'D');}
}

int main(){
	memset(dp2,0x3f,sizeof(dp2));
	memset(dp5,0x3f,sizeof(dp5));
	dp2[1][1]=dp5[1][1]=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		scanf("%d",&k);
    		if(!k){a[i][j]=b[i][j]=1000;sb1=i;sb2=j;continue;}
    		while(!(k%2)){k/=2;a[i][j]++;}
    		while(!(k%5)){k/=5;b[i][j]++;}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i+j==2){dp2[i][j]=a[i][j];dp5[i][j]=b[i][j];continue;}
			if(dp2[i-1][j]<dp2[i][j-1]){dp2[i][j]=dp2[i-1][j]+a[i][j];}
			else{op2[i][j]=1;dp2[i][j]=dp2[i][j-1]+a[i][j];}
			if(dp5[i-1][j]<dp5[i][j-1]){dp5[i][j]=dp5[i-1][j]+b[i][j];}
			else{op5[i][j]=1;dp5[i][j]=dp5[i][j-1]+b[i][j];}
		}
	}
	if(dp2[n][n]>1&&dp5[n][n]>1&&sb1){ans0();return 0;}
	if(dp2[n][n]<dp5[n][n]){ans2();}
	else{ans5();}
}