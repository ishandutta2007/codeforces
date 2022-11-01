#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define _(x)(x&-x)
#define ch(a,v)(chx(a.y,a.x+a.y+a.len,v))
using namespace std;
const int N=1e5+5,M=5005;
int n,q,qs;
struct op{int op,x,y,len;}a[N],b[N],c[N];
int t[M][M*2],an[N];
void chx(int x,int y,int v){
	for(;x<=n;x+=_(x))
		for(int i=y;i;i-=_(i))
			t[x][i]+=v;
}
int qu(int x,int y){
	int s=0;
	for(;x;x-=_(x))
		for(int i=y;i<=n+n;i+=_(i))
			s+=t[x][i];
	return s;
}
void cdq(int l,int r){
	if(l==r)return;
	int m=l+r>>1;
	cdq(l,m);cdq(m+1,r);
	int can=0;
	fo(i,l,m)if(b[i].op!=5){can=1;break;}
	if(can){
		can=0;
		fo(i,m+1,r)if(b[i].op==5){can=1;break;}
	}
	int j=l,w=l;
	fo(i,m+1,r){
		for(;j<=m&&b[j].x<=b[i].x;){
			can&&b[j].op<5?ch(b[j],1),0:0;
			c[w++]=b[j++];
		}
		can&&b[i].op==5?an[b[i].len]+=qu(b[i].y,b[i].x+b[i].y):0;
		c[w++]=b[i];
	}
	if(can)fo(i,l,j-1)b[i].op<5?ch(b[i],-1),0:0;
	for(;j<=m;)c[w++]=b[j++];
	memcpy(b+l,c+l,sizeof(op)*(r-l+1));
}
void get(int o,int r1,int r2){
	int bs=0;
	fo(i,1,q)if(a[i].op==o||a[i].op==5)
		b[++bs]=a[i],(r1?b[bs].x=n-b[bs].x+1:0),(r2?b[bs].y=n-b[bs].y+1:0);
	cdq(1,bs);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>q;
	fo(i,1,q){
		cin>>a[i].op;
		if(a[i].op==1)cin>>a[i].op>>a[i].x>>a[i].y>>a[i].len;
		else a[i].op=5,cin>>a[i].x>>a[i].y,a[i].len=++qs;
	}
	get(1,0,0);
	get(2,0,1);
	get(3,1,0);
	get(4,1,1);
	fo(i,1,qs)cout<<an[i]<<endl;
}