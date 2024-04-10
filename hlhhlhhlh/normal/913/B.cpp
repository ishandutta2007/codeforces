#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k,n,m,b[maxn],x,fla;
int r,f1[maxn],f2[maxn],f3[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void work(int x,int fa){
	int i=f1[x],t1=0;
	while (i!=0){
		if (f2[i]!=fa){
			work(f2[i],x);
			if (b[f2[i]]==0) t1++;
		}
		i=f3[i];
	}
	if ((b[x]!=0)&&(t1<3)) fla=0;
}
int main(){
	n=read();
	memset(b,0,sizeof(b));
	for (i=2;i<=n;i++){
		x=read();
		b[x]++;
		r++; f2[r]=x; f3[r]=f1[i]; f1[i]=r;
		r++; f2[r]=i; f3[r]=f1[x]; f1[x]=r;
	}
	fla=1;
	work(1,0);
	if (fla==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}