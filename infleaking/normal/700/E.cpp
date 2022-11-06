#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=4e5+10,M=N*60;
int las,t,step[N],trans[N][26],pre[N];
int tr[M],c[M][2],pos[N],n,r[N],m,rt[N];
int getp(int x){
	step[++m]=step[x]+1;
	return m;
}
int extend(int x){
	int np=getp(las),p=las;
	for (;p&&!trans[p][x];p=pre[p])trans[p][x]=np;
	if (!p){
		pre[np]=1;
		return np;
	}
	int q=trans[p][x];
	if (step[q]!=step[p]+1){
		int nq=getp(p);
		for (;p&&trans[p][x]==q;p=pre[p])trans[p][x]=nq;
		memcpy(trans[nq],trans[q],sizeof trans[q]);
		pre[nq]=pre[q];
		pre[q]=pre[np]=nq;
	}else pre[np]=q;
	return np;
}
bool comp(int a,int b){return step[a]>step[b];}
#define x1 c[x][0]
#define x2 c[x][1]
#define md (l+r>>1)
void build(int &x,int l,int r,int px){
	tr[x=++t]=1;
	if (l==r)return;
	if (px<=md)build(x1,l,md,px);
	else build(x2,md+1,r,px);
}
int clone(int x,int y){
	tr[x]=tr[y];
	x1=c[y][0],x2=c[y][1];
	return x;
}
int merge(int x0,int y0){
	int x=++t;
	if (!x0||!y0)return clone(x,x0^y0);
	x1=merge(c[x0][0],c[y0][0]);
	x2=merge(c[x0][1],c[y0][1]);
	tr[x]=tr[x0]+tr[y0];
	return x;
}
int dp[N],top[N];
int pl,pr;
int query(int x,int l,int r){
	if (!x||r<pl||pr<l)return 0;
	if (pl<=l&&r<=pr)return tr[x];
	return query(x1,l,md)+query(x2,md+1,r);
}
int main(){
	cin>>n;
	scanf("\n");
	las=m=1;
	for (int i=1;i<=n;i++)
		las=extend(getchar()-'a'),pos[las]=i;
	for (int i=1;i<=m;i++){
		r[i]=i;
		if (pos[i])build(rt[i],1,n,pos[i]);
	}
	sort(r+1,r+m+1,comp);
	for (int i=1;i<=m;i++){
		int x=r[i];
		rt[pre[x]]=merge(rt[pre[x]],rt[x]);
		pos[pre[x]]=max(pos[pre[x]],pos[x]);
	}
	reverse(r+1,r+m+1);
	int ans=1;
	for (int i=2;i<=m;i++){
		int x=r[i];
		if (pre[x]==1){
			dp[x]=1;
			top[x]=x;
			continue;
		}
		top[x]=top[pre[x]];
		dp[x]=dp[top[x]];
		pl=pos[x]-step[x]+step[top[x]],pr=pos[x];
		int z=query(rt[top[x]],1,n);
		if (z>=2){
			top[x]=x;
			ans=max(ans,++dp[x]);
		}
	}
	cout<<ans<<endl;
}