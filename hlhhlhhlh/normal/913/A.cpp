#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m,i,j,k,t1,t2;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	t1=1;
	for (i=1;i<=n;i++){
		t1=t1*2;
		if (m<t1){
			printf("%d\n",m);
			return 0;
		}
	}
	printf("%d\n",m%t1);
	return 0;
}