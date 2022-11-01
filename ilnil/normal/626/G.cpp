#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define db double
#define P pair<db,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
int n,T,q,op,y;
int p[N],l[N],x[N];
struct tree{
	db ans,mx,mi;
	int pos1,pos2;
	void get(int i){
		ans=min((db)p[i]/2,(db)p[i]*x[i]/(l[i]+x[i]));
		if(x[i]>=l[i])mx=0;
		else mx=(db)p[i]*l[i]/(l[i]+x[i]+1)/(l[i]+x[i]);
		if(!x[i])mi=1e15;else
		if(x[i]>l[i])mi=0;else
			mi=(db)p[i]*l[i]/(l[i]+x[i])/(l[i]+x[i]-1);
		pos1=pos2=i;
	}
}t[N*4];
void up(tree &z,tree x,tree y){
	z.ans=x.ans+y.ans;
	z.mx=max(x.mx,y.mx);
	z.pos1=z.mx==x.mx?x.pos1:y.pos1;
	z.mi=min(x.mi,y.mi);
	z.pos2=z.mi==x.mi?x.pos2:y.pos2;
}
void B(int v,int l,int r){
	if(l==r){
		t[v].get(l);
		return;
	}
	int m=l+r>>1;
	B(v*2,l,m);B(v*2+1,m+1,r);
	up(t[v],t[v*2],t[v*2+1]);
}
void ch(int v,int l,int r,int x){
	if(l==r){
		t[v].get(l);
		return;
	}
	int m=l+r>>1;
	if(x<=m)ch(v*2,l,m,x);else ch(v*2+1,m+1,r,x);
	up(t[v],t[v*2],t[v*2+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>T>>q;
	fo(i,1,n)cin>>p[i];
	fo(i,1,n)cin>>l[i];
	B(1,1,n);
	fo(i,1,T)++x[t[1].pos1],ch(1,1,n,t[1].pos1);
	for(;q--;){
		cin>>op>>y;
		l[y]+=op==1?1:-1;
		ch(1,1,n,y);
		if(t[1].mx-t[1].mi>1e-8){
			++x[t[1].pos1];
			y=t[1].pos2;--x[y];
			ch(1,1,n,t[1].pos1);
			ch(1,1,n,y);
		}
		printf("%.10lf\n",t[1].ans);
	}
}