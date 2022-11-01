#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define ll long long
#define B cout<<"Breakpoint"<<endl;
#define O(x) cout<<#x<<" "<<x<<endl;
#define o(x) cout<<#x<<" "<<x<<" ";
using namespace std;
int read(){
	int x = 1,a = 0;char ch = getchar();
	while (ch < '0'||ch > '9'){if (ch == '-') x = -1;ch = getchar();}
	while (ch >= '0'&&ch <= '9'){a = a*10+ch-'0';ch = getchar();}
	return x*a;
}
const int maxn = 2e5+10;
int n,col[maxn];
struct node{
	int to,nxt;
}ed[maxn<<1];
int head[maxn],tot;
void add(int u,int to){
	ed[++tot].to = to;
	ed[tot].nxt = head[u];
	head[u] = tot;
}
struct SEGTree{
	int l,r,sum;
	ll ans;
}t[10000000];
void pushup(int x){
	int l = t[x].l,r = t[x].r;
//	cout<<"pushup =  = "<<l<<" "<<r<<" "<<t[l].sum<<" "<<t[x].ans<<" "<<t[r].sum<<" "<<t[r].ans<<endl;
	if (t[l].sum > t[r].sum){
		t[x].ans = t[l].ans;
		t[x].sum = t[l].sum;
	}
	if (t[r].sum > t[l].sum){
		t[x].ans = t[r].ans;
		t[x].sum = t[r].sum;
	}
	if (t[l].sum == t[r].sum){
		t[x].sum = t[l].sum;
		t[x].ans = t[l].ans+t[r].ans;
	}
//	cout<<"pushup = "<<t[x].sum<<" "<<t[x].ans<<endl;
}
int cnt;
void modify(int &x,int lst,int l,int r,int p,int k){
	if (!x) x = ++cnt;
	if (l == r){
		t[x].sum = t[lst].sum+1;
		t[x].ans = l;
//		cout<<"modify = "<<x<<" "<<l<<" "<<t[x].sum<<" "<<t[x].ans<<endl;
		return;
	}
	int mid = (l+r >> 1);
	if (p <= mid) t[x].r = t[lst].r,modify(t[x].l,t[lst].l,l,mid,p,k);
	else t[x].l = t[lst].l,modify(t[x].r,t[lst].r,mid+1,r,p,k);
//	cout<<x<<" "<<t[x].l<<" "<<t[x].r<<endl;
	pushup(x);
}
int merge(int a,int b,int l,int r){
	if (!a) return b;
	if (!b) return a;
	int res = a;
	if (l == r){
		t[res].sum = t[a].sum+t[b].sum;
		t[res].ans = l;
		return res;
	}
	int mid = (l+r >> 1);
	t[res].l = merge(t[a].l,t[b].l,l,mid);
	t[res].r = merge(t[a].r,t[b].r,mid+1,r);
//	cout<<l<<" "<<r<<endl;
//	cout<<"merge = "<<a<<" "<<t[a].sum<<" "<<t[a].ans<<" "<<b<<" "<<t[b].sum<<" "<<t[b].ans<<endl;
//	cout<<"res = "<<res<<" "<<t[res].l<<" "<<t[res].r<<endl;
	pushup(res);
	return res;
}
int root[maxn];
ll ans[maxn];
void dfs(int x,int fa){
	for (int i = head[x];i;i = ed[i].nxt){
		int to = ed[i].to;
		if (to == fa) continue;
		dfs(to,x);
		root[x] = merge(root[x],root[to],1,n);
	}
	modify(root[x],root[x],1,n,col[x],1);
	ans[x] = t[root[x]].ans;
}
int main(){
	n = read();
	for (int i = 1;i <= n;i++) col[i] = read();
	for (int i = 1;i < n;i++){
		int x = read(),y = read();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for (int i = 1;i <= n;i++) printf("%lld ",ans[i]);
	return 0;
}