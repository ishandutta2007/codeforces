// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9;
long long i,j,k;
long long n,m;
long long t1,t2,t3,t4,t5,t6;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	if (n>m) swap(n,m);
	if (m<=2){ printf("0\n"); return 0; }
	if (m==3){
		if (n==2) printf("4\n");
		if (n==3) printf("8\n");
		if (n==1) printf("0\n");
		return 0;
	}
	if (n==1){
		t1=(m/6)*6; m=m%6;
		if (m==4) t1=t1+2;
		if (m==5) t1=t1+4;
		if (m==6) t1=t1+6;
		printf("%I64d\n",t1);
		return 0;
	}
	if (n==2){
	    if (m==7){
	        printf("12\n");
	        return 0;
	    }
	}
	if ((n*m)%2==1){
		printf("%I64d\n",(n*m)-1);
	}
	else{
		printf("%I64d\n",n*m);
	}
	return 0;
}