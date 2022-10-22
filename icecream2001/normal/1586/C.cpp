#include<bits/stdc++.h>
#define LL long long
using namespace std;
static char ss[1<<17],*A=ss,*B=ss;
char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
const LL P=1e6;
int n,m;
char s[2][1000005];
int vis[1000005];
set<int> S;
void MAIN(){
	int sum=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;++i) vis[i]=0;
	S.clear();
	int cur=1;
	scanf("%s",s[0]+1);
	for(int i=2;i<=n;++i){
		scanf("%s",s[cur]+1);
		for(int j=1;j<m;++j){
			if(s[cur][j]=='X'&&s[cur^1][j+1]=='X'){
				vis[j]=j;
			}
		}
		cur^=1;
	}
	vis[m+1]=m+1;
	for(int i=m;i>=1;--i) if(!vis[i]) vis[i]=vis[i+1];
	int Q;scanf("%d",&Q);
	int l,r,x;
	while(Q--){
		scanf("%d%d",&l,&r);
		x=vis[l];
		if(r>=x+1) puts("NO");
		else puts("YES");
	}
	return;
	//scanf("%d",&n);
} 

int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}
/*
*/