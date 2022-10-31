#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,l[200500],r[200500],sb[200500],a[200500];
char s[200500],s2[200500];
string res;
void dfs(int x){if(!x)return;dfs(l[x]);s2[++k]=s[x];dfs(r[x]);}
void dfs2(int x,int y){
	if(!x)return;
	dfs2(l[x],y+1);
	res+=s2[++j];
	sb[x]=sb[l[x]];
	if(!sb[x]&&a[j]&&y<=m)m-=y,sb[x]=1;
	if(sb[x])res+=s2[j],dfs2(r[x],1);
	else dfs2(r[x],1e9);
}
int main() {
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++)cin>>l[i]>>r[i];dfs(1);
	for(i=n;i>=1;i--)a[i]=((s2[i]==s2[i+1])?a[i+1]:(s2[i]<s2[i+1]));dfs2(1,1);
	cout<<res;
}