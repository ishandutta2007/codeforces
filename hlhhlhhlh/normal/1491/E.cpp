// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=400010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,x,y;
int f1[maxn],f2[maxn],f3[maxn],th;
int siz[maxn],ha[maxn],w,ww,faa[maxn];
long long f[maxn];
void add(int x,int y){
	th++; f2[th]=y; f3[th]=f1[x]; f1[x]=th;
}
void dfs(int x,int fa){
	siz[x]=1;
	for (int i=f1[x];i!=0;i=f3[i]){
		if ((f2[i]!=fa)&&(f2[i]!=0)){
			dfs(f2[i],x); faa[f2[i]]=i;
			siz[x]=siz[x]+siz[f2[i]];
		}
	}
	if ((siz[x]==ha[ww])||(siz[x]==ha[ha[ww]])) w=x;
}
int solve(int x,int n){
	if ((n==1)||(n==2)) return 1;
	w=0; ww=n; dfs(x,x);
	if (w==0) return 0;
	f2[faa[w]]=0; if (faa[w]%2==1) f2[faa[w]+1]=0; else f2[faa[w]-1]=0;
	int t=w,tt=siz[w]; return (solve(t,tt)+solve(x,n-tt)==2);
}
int main(){
	
	n=read();
	for (i=1;i<n;i++){
		x=read(); y=read();
		add(x,y); add(y,x);
	}
	f[0]=1; f[1]=1;
	for (i=2;i<=50;i++) f[i]=f[i-1]+f[i-2];
	for (i=1;i<=50;i++) if (f[i]<=n) ha[f[i]]=f[i-1];
	if (ha[n]==0){
		printf("NO\n"); return 0;
	}
	if (solve(1,n)==1) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}