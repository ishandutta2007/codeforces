// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j;
int T,opt;
int n;
double m,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read();
		if (n==0){
			printf("Y 0 0\n"); continue;
		}
		if (n<4){
			printf("N\n"); continue;
		}
		else{
			m=n/2.0; k=m/2.0;
			while (fabs(m*(n-m)-n)>=1e-7){
				if (m*(n-m)>=n){
					m=m-k;
				}
				else{
					m=m+k;
				}
				k=k/2;
			}
			printf("Y %.9lf %.9lf\n",n-m,m);
		}
	}
	return 0;
}