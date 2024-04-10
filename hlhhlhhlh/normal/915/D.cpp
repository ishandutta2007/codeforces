#include<bits/stdc++.h>
using namespace std;
const int maxn=300010;
int i,j,k,n,m,x,y,s;
int r,f1[maxn],f2[maxn],f3[maxn],ha[maxn],vis[maxn],fla,thi,ans;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void dfs(int x){
	int i=f1[x];
	vis[x]=1;
	while (i!=0){
		if (f2[i]==s){
			ha[i]++;
		}
		if (vis[f2[i]]==0){
			dfs(f2[i]);
		}
		i=f3[i];
	}
}
void tarjan(int x){
	int i=f1[x];
	if (ha[x]==1){ fla=1; return; }
	vis[x]=1; ha[x]=1;
	while (i!=0){
		if ((i!=thi)&&(vis[f2[i]]==0)) tarjan(f2[i]);
		else{
			if (i!=thi){
				if (ha[f2[i]]==1){
					fla=1; return;
				}
			}
		}
		i=f3[i];
	}
	ha[x]=0;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=m;i++){
		x=read(); y=read();
		r++; f2[r]=y; f3[r]=f1[x]; f1[x]=r;
	}
	fla=0;
	thi=0;
	for (i=1;i<=n;i++){
		if (vis[i]==0) tarjan(i);
	}
	if (fla==0){
		printf("YES\n");
		return 0;
	}
	for (i=1;i<=n;i++){
		memset(ha,0,sizeof(ha));
		memset(vis,0,sizeof(vis));
		s=i; dfs(i);
		fla=0;
		for (j=1;j<=2*m;j++){
			fla=fla+ha[j];
			if (ha[j]==1) thi=j; 
		}
		if (fla==1){
			memset(vis,0,sizeof(vis));
			memset(ha,0,sizeof(ha));
			fla=0;
			for (j=1;j<=n;j++){
				if (vis[j]==0) tarjan(j);
			}
			if (fla==0){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}