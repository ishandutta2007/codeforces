// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
long long n,m,i,j,k,ans,T,opt,anss,tt;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); m=read(); k=read();
		ans=max(n,m);
		anss=min(n,m);
		tt=k-((ans-anss)%2);
		if (k<ans) printf("-1\n");
		else{
			if (k==ans) printf("%I64d\n",tt);
			else{
				if ((n+m)%2==0){
					if ((k-ans)%2==0) printf("%I64d\n",k); else printf("%I64d\n",k-2);
				}
				else printf("%I64d\n",k-1);
			}
		}
	}
	return 0;
}