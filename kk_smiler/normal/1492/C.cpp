#include <bits/stdc++.h>
using namespace std;
int n,m,T,p,nxt[200010][30],pre[200010][30],pp[200010],ps[200010];
char s[200010],t[200010];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i+1]-'a']=i+1;
	}
	for(int i=2;i<=n+1;i++){
		for(int j=0;j<26;j++) pre[i][j]=pre[i-1][j];
		pre[i][s[i-1]-'a']=i-1;
	}
	int nw=0;
	for(int i=1;i<=m;i++) nw=nxt[nw][t[i]-'a'],pp[i]=nw;
	nw=n+1;
	for(int i=m;i>=1;i--) nw=pre[nw][t[i]-'a'],ps[i]=nw;
	int ans=0;
	for(int i=1;i<=m;i++){
		if(i!=m) ans=max(ans,ps[i+1]-nxt[pp[i-1]][t[i]-'a']);
		if(i!=1) ans=max(ans,pre[i+1][t[i]-'a']-pp[i-1]);
	}
	printf("%d\n",ans);
}