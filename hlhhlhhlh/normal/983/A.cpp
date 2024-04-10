// user:halahen
#include<bits/stdc++.h>
using namespace std;
const long long maxn=100010;
long long i,j,k,b[maxn];
long long opt,T,x,y,z,a;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long gcd(long long x,long long y){
	long long t1;
	if (x<y) swap(x,y);
	while (y!=0){
		t1=x%y;
		x=y; y=t1;
	}
	return x;
}
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		x=read(); y=read(); z=read();
		x=x%y;
		if (x==0){
			printf("Finite\n");
			continue;
		}
		a=gcd(x,y);
		x=x/a; y=y/a;
		while (y%z==0) y=y/z;
		a=gcd(y,z);
		while (a!=1){
			y=y/a; a=gcd(y,a);
		}
		if (y==1){
			printf("Finite\n");
		}
		else{
			printf("Infinite\n");
		}
	}
	return 0;
}