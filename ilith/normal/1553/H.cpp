#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
using namespace std;
typedef long long ll;
const int N=6e5+7;
int n,k,S,x,ans[N];
struct node{int l,r,mn;};
node mg(node x,node y,int d){
	if(y.l<0)return x.r+=d,x;
	if(x.l<0)return y.l+=d,y;
	return {x.l,y.r,min(min(x.mn,y.mn),x.r+y.l+1)};
}
void solve(vector<node>s,int x,int d){
	if(d==S)return void(ans[x]=s[0].mn);
	int sz=s.size();
	vector<node>l(sz/2),r(sz/2);
	for(int i=0;i<sz;i+=2)l[i/2]=mg(s[i],s[i+1],d),r[i/2]=mg(s[i+1],s[i],d);
	solve(l,x,d<<1),solve(r,x+d,d<<1);
}
signed main(){
	scanf("%d%d",&n,&k);
	vector<node>c(S=1<<k);
	FOR(i,0,S-1)c[i]={-N,-N,N};
	FOR(i,1,n)scanf("%d",&x),c[x].l=c[x].r=0;
	solve(c,0,1);
	FOR(i,0,S-1)printf("%d ",ans[i]);
	return 0;
}