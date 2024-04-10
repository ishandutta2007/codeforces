// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int n;
int a[maxn],mx,t,ans,fla,anss;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	for (i=2;i<=n;i++){
		while (n%i==0){
			n=n/i; a[i]++;
		}
	}
	for (i=1;i<=1e6;i++){
		mx=max(a[i],mx);
	}
	t=1; while (t<mx) t=t*2; fla=0; anss=1;
	for (i=1;i<=1e6;i++){
		if ((a[i]!=0)&&(a[i]!=t)){
			a[i]=t; fla=1;
		}
		if (a[i]!=0){
			anss=anss*i;
		}
	}
	ans=ans+fla;
	while (t!=1){
		t=t/2; ans++;
	}
	printf("%d %d\n",anss,ans);
	return 0;
}