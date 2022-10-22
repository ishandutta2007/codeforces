#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt;
int n;
int i,j,k,thi,ans;
const int maxn=100010;
struct node{
	int a[5];
}a[maxn];
bool operator < (node a,node b){
	int tot=0;
	for (int i=0;i<5;i++) if (a.a[i]<b.a[i]) tot++;
	if (tot>=3) return 1; else return 0;
}
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read();
		for (i=1;i<=n;i++){
			for (j=0;j<5;j++){
				a[i].a[j]=read(); 
			}
		}
		thi=1;
		for (i=2;i<=n;i++){
			if (a[i]<a[thi]) thi=i;
		}
		ans=0;
		for (i=1;i<=n;i++){
			if ((thi==i)||(a[thi]<a[i])) ans++;
		}
		if (ans==n) printf("%d\n",thi); else printf("-1\n");
	}

	return 0;
}