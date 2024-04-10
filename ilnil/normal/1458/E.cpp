#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
using namespace std;
const int N=1e5+5;
int n,m;
bool ans[N];
map<int,bool>ex;
struct nod{int x,y,op;}a[N+N];
struct node{
	int x,len;
	node(int _x=0,int _len=0){x=_x;len=_len;}
	bool operator<(const node b)const{return x<b.x;}
};
set<node>A;
bool cmp(nod a,nod b){
	if(a.x!=b.x)return a.x<b.x;
	if(a.op!=b.op)return a.op<b.op;
	return a.y<b.y;
}
void move(int len){
	for(;;){
		node x=*A.begin();
		A.erase(x);
		if(len<x.len){
			x.len-=len;x.x+=len;
			A.insert(x);
			break;
		}
		len-=x.len;
	}
}
void del(int x){
	auto i=A.upper_bound(node(x,0));
	if(i==A.begin())return;
	--i;
	if((*i).x+(*i).len-1>=x){
		node y=*i;
		A.erase(i);
		if(x-y.x>0)A.insert(node(y.x,x-y.x));
		if(y.x+y.len-1>x)A.insert(node(x+1,y.x+y.len-1-x));
	}
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n)scanf("%d%d",&a[i].x,&a[i].y),a[i].op=0;
	fo(i,1,m)scanf("%d%d",&a[n+i].x,&a[n+i].y),a[n+i].op=i;
	n+=m;
	sort(a+1,a+n+1,cmp);
	A.insert(node(0,2e9+10));
	for(int i=1,las=-1;i<=n;++i){
		int j=i;
		for(;j<=n&&a[i].x==a[j].x;)++j;
		move(a[i].x-las-1);
		ex.clear();
		int c=(*A.begin()).x;
		if(a[i].op||a[i].op==0&&c<a[i].y)
			ex[c]=1;
		fo(k,i,j-1){
			if(a[k].op)break;
			ex[a[k].y]=1;
		}
		fo(k,i,j-1)if(a[k].op)
			ans[a[k].op]=!ex.count(a[k].y);
		for(auto k:ex)del(k.first);
		las=a[i].x;
		i=j-1;
	}
	fo(i,1,m)printf(ans[i]?"WIN\n":"LOSE\n");
}