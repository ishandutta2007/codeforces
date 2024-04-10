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
long long n,s,t,d,t1,t2,T,opt;
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); s=read(); t=read(); d=read();
		if (abs(s-t)%d==0){
			printf("%I64d\n",abs(s-t)/d);
		}
		else{
			t1=1e18;
			if (abs(1-t)%d==0){
				t1=abs(1-t)/d;
				t1=t1+(s-1)/d+(((s-1)%d)!=0);
			}
			t2=1e18;
			if (abs(n-t)%d==0){
				t2=abs(n-t)/d;
				t2=t2+(n-s)/d+(((n-s)%d)!=0);
			}
			if ((t1!=1e18)||(t2!=1e18)){
				printf("%I64d\n",min(t1,t2));
			}
			else printf("-1\n");
		}
	}
	return 0;
}