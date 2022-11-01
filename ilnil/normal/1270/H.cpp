#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
using namespace std;
const int N=5e5+5,inf=2e6;
int n,q,x,p;
int a[N];
struct nod{
	int mx,mn,l,r;
}t[N*4];
int qu(int v,int l,int r,int x,int y){
	if(l==r||x<=t[v].mn||y>=t[v].mx||x<=y)return 0;
	int m=l+r>>1,_mn=min(x,t[v*2].mn),_mx=max(y,t[v*2+1].mx),tot=_mn>_mx;
	if(x>t[v*2].mx&&_mx==t[v*2+1].mx)tot+=t[v].l;else tot+=qu(v*2,l,m,x,_mx);
	if(y<t[v*2+1].mn&&_mn==t[v*2].mn)tot+=t[v].r;else tot+=qu(v*2+1,m+1,r,_mn,y);
	return tot;
}
void up(int v,int l,int r){
	t[v].mx=max(t[v*2].mx,t[v*2+1].mx);
	t[v].mn=min(t[v*2].mn,t[v*2+1].mn);
	int m=l+r>>1;
	t[v].l=qu(v*2,l,m,inf,t[v*2+1].mx);
	t[v].r=qu(v*2+1,m+1,r,t[v*2].mn,-inf);
}
void B(int v,int l,int r){
	if(l==r){
		t[v].mx=t[v].mn=a[l];
		return;
	}
	int m=l+r>>1;
	B(v*2,l,m);B(v*2+1,m+1,r);
	up(v,l,r);
}
void ch(int v,int l,int r,int x,int p){
	if(l==r){
		t[v].mx=t[v].mn=p;
		return;
	}
	int m=l+r>>1;
	if(x<=m)ch(v*2,l,m,x,p);else ch(v*2+1,m+1,r,x,p);
	up(v,l,r);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	fo(i,1,n)cin>>a[i];
	B(1,1,n);
	fo(i,1,q){
		cin>>x>>p;
		ch(1,1,n,x,p);
		printf("%d\n",qu(1,1,n,inf,-inf)+1);
	}
}