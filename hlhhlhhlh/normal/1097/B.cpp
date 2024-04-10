// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
int i,j,k,fla,n;
int a[maxn],b[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void check(){
	int i,ans=0;
	for (i=1;i<=n;i++){
		ans=ans+b[i]*a[i];
	}
	if ((ans+360*360)%360==0){
		fla=1;
	}
}
void dfs(int x){
	if (x>n){
		check();
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=-1;
	dfs(x+1);
}
int main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	dfs(1);
	if (fla==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}