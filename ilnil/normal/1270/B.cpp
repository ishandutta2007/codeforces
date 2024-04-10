#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define mp make_pair
#define P pair<int,int>
using namespace std;
const int N=2e5+5;
int T,n;
int a[N];
int le,ri;
bool bz;
struct tree{
	pair<int,int> a,b,c;
}t[N*4];
void mer(tree &z,tree x,tree y){
	z.a=min(x.a,y.a);
	z.b=max(x.b,y.b);
	z.c=max(x.c,y.c);
}
void B(int v,int l,int r){
	if(l==r){
		t[v].a=mp(a[l],l);
		t[v].b=mp(a[l]-l,l);
		t[v].c=mp(a[l]+l,l);
		return;
	}
	int m=l+r>>1;
	B(v*2,l,m);
	B(v*2+1,m+1,r);
	mer(t[v],t[v*2],t[v*2+1]);
}
pair<int,int> qua(int v,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return t[v].a;
	int m=l+r>>1;
	P a=P(2e9,0),b=P(2e9,0);
	if(x<=m)a=qua(v*2,l,m,x,y);
	if(m<y)b=qua(v*2+1,m+1,r,x,y);
	return min(a,b);
}
pair<int,int> qub(int v,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return t[v].b;
	int m=l+r>>1;
	P a=P(-1e9,0),b=P(-1e9,0);
	if(x<=m)a=qub(v*2,l,m,x,y);
	if(m<y)b=qub(v*2+1,m+1,r,x,y);
	return max(a,b);
}
pair<int,int> quc(int v,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return t[v].c;
	int m=l+r>>1;
	P a=P(-1e9,0),b=P(-1e9,0);
	if(x<=m)a=quc(v*2,l,m,x,y);
	if(m<y)b=quc(v*2+1,m+1,r,x,y);
	return max(a,b);
}
void find(int l,int r){
	if(bz||l>=r)return;
	int m=qua(1,1,n,l,r).second;
	P x=qub(1,1,n,m,r);
	if(x.first>=a[m]-m+1){
		bz=1;
		le=m;ri=x.second;
	}
	x=quc(1,1,n,l,m);
	if(x.first>=a[m]+m+1){
		bz=1;
		le=x.second;ri=m;
	}
	find(l,m-1);
	find(m+1,r);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	for(;T--;){
		cin>>n;
		fo(i,1,n)cin>>a[i];
		B(1,1,n);
		bz=0;
		find(1,n);
		if(bz){
			printf("YES\n%d %d\n",le,ri);
		}else printf("NO\n");
	}
}