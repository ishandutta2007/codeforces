// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int a[maxn],n;
int t2,tot;
int T,opt;
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); t2=0; tot=0;
		for (i=1;i<=n;i++) a[i]=read();
		for (i=1;i<=n;i++){
			t2=max(t2,a[i]);
			tot=tot+a[i];
		}
		if (t2>=(tot/2)+1){
			printf("T\n");
			continue;
		}
		if (tot%2==1){
			printf("T\n");
		}
		else{
			printf("HL\n");
		}
	}
	
	return 0;
}