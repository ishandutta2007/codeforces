#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k,n,m,l,r,ans;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read(); l=read(); r=read();
	if (m>r){
		ans=(m-r)+1;
		if (l!=1) ans=ans+(r-l)+1;
	}
	if (m<l){
		ans=(l-m)+1;
		if (r!=n) ans=ans+(r-l)+1;
	}
	if ((l<=m)&&(m<=r)){
		if ((l==1)&&(r==n)){
		}
		else{
		if (l==1){
			ans=(r-m)+1;
		}
		else{
			if (r==n){
				ans=(m-l)+1;
			}
			else{
				ans=min(r-m,m-l)+1;
				ans=ans+(r-l)+1;
			}
		}
		}
	}
	printf("%d\n",ans);
	return 0;
}