/*********************************************************************
	Problem:CF700E
	Author:hydd
	Date:2020/7/27
*********************************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int S=1;
int z,n,cnt,a[410000],c[410000],len[410000];
int f[410000],g[410000];
int link[410000],trans[410000][26],num[410000];
int treesize,ls[11000000],rs[11000000],rt[410000];
char s[410000];
void change(int &now,int l,int r,int x){
	if (!now) now=++treesize;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) change(ls[now],l,mid,x);
	else change(rs[now],mid+1,r,x);
}
int merge(int x,int y){
	if (!x||!y) return x|y;
	int z=++treesize;
	ls[z]=merge(ls[x],ls[y]);
	rs[z]=merge(rs[x],rs[y]);
	return z;
}
bool query(int now,int l,int r,int x,int y){
	if (!now) return false;
	if (l==x&&r==y) return true;
	int mid=(l+r)>>1;
	if (y<=mid) return query(ls[now],l,mid,x,y);
	else if (x>mid) return query(rs[now],mid+1,r,x,y);
	else return query(ls[now],l,mid,x,mid)||query(rs[now],mid+1,r,mid+1,y);
}
void add(int loc){
	int c=s[loc]-'a',v=z;
	z=++cnt; len[z]=loc; num[z]=loc;
	for (;v&&!trans[v][c];v=link[v]) trans[v][c]=z;
	if (!v) link[z]=S;
	else{
		int x=trans[v][c];
		if (len[v]+1==len[x]) link[z]=x;
		else
		{
			int y=++cnt; len[y]=len[v]+1; num[y]=num[z];
			for (int i=0;i<26;i++) trans[y][i]=trans[x][i];
			link[y]=link[x]; link[x]=y; link[z]=y;
			for (;trans[v][c]==x;v=link[v]) trans[v][c]=y;
		}
	}
}
int solve(){
	z=1; cnt=1;
	for (int i=1;i<=n;i++) add(i),change(rt[z],1,n,i);
	for (int i=1;i<=cnt;i++) c[len[i]]++;
	for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
	for (int i=1;i<=cnt;i++) a[c[len[i]]--]=i;
	for (int i=cnt;i>=2;i--)
		rt[link[a[i]]]=merge(rt[link[a[i]]],rt[a[i]]);
	
	int ans=1;
	for (int i=2;i<=cnt;i++){
		int x=a[i],y=link[x];
		if (y==1){
			f[x]=1; g[x]=x;
			continue;
		}
		int t=query(rt[g[y]],1,n,num[x]-len[x]+len[g[y]],num[x]-1);
		f[x]=f[y]+t; g[x]=t?x:g[y];
		ans=max(ans,f[x]);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	printf("%d\n",solve());
	return 0;
}