// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int b[maxn];
int n,l,r,mid,thi,thil,thir;
int q(int x){
	if (b[x]!=0) return b[x];
	printf("? %d\n",x); fflush(stdout);
	return read();
}
int main(){
	
	n=read();
	l=1; r=n; b[0]=n+1; b[n+1]=n+2;
	while (l<=r){
		mid=(l+r)/2;
		thi=q(mid);
		thil=q(mid-1);
		thir=q(mid+1);
		if ((thi<thil)&&(thi<thir)){
			printf("! %d\n",mid); return 0;
		}
		if (thi>thil) r=mid-1; else l=mid+1;
	}
	
	return 0;
}