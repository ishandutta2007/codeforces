#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,a[100010],ans[100010],cnt,nxt[100010];
bool del[100010];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
queue<int>q;
void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]),nxt[i]=(i+1)%n,del[i]=false;
	for(int i=0;i<n;i++) if(gcd(a[i],a[nxt[i]])==1) q.push(i);
	cnt=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(del[u]) continue;
		ans[++cnt]=nxt[u],del[nxt[u]]=true;
		nxt[u]=nxt[nxt[u]];
		if(gcd(a[u],a[nxt[u]])==1) q.push(u);
	}
	printf("%d ",cnt);
	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]+1);puts("");
}
int main(){
	if(1) scanf("%d",&T);
	else T=1;
	while(T--) solve();
}