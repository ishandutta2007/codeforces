#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
using namespace std;
const int N=1.5e5+5;
int n,m,p,op,pl,pr,id,nd,a[N],ad[N*4],sz[N*4];
struct no{
	int a,c;
	bool operator<(const no &b)const{return c>b.c;}
}s[15];
struct nod{
	int g;
	no a[7];
}t[N*4],ans;
priority_queue<no>A;
void add(int &g,no a){
	if(!g||a.a!=s[g].a)s[++g]=a;
	else s[g].c+=a.c;
}
bool cmp(no a,no b){return a.a<b.a;}
void mer(nod &z,nod x,nod y){
	int g=0,i=1,j=1;
	for(;i<=x.g||j<=y.g;)
		if(j>y.g||i<=x.g&&x.a[i].a<y.a[j].a)add(g,x.a[i++]);
		else add(g,y.a[j++]);
	if(g>=nd){
		fo(i,1,g)A.push(s[i]);
		for(;A.size()>=nd;){
			fo(i,1,nd)s[i]=A.top(),A.pop();
			int mi=s[1].c;
			fo(i,1,nd)if(s[i].c-=mi)A.push(s[i]);
		}
		g=0;
		for(;A.size();A.pop())s[++g]=A.top();
		sort(s+1,s+g+1,cmp);
	}
	z.g=g;
	fo(i,1,g)z.a[i]=s[i];
}
void B(int v,int l,int r){
	if(l==r){
		t[v].g=1;
		t[v].a[1]=(no){a[l],1};
		sz[v]=1;
		return;
	}
	int m=l+r>>1;
	B(v*2,l,m);B(v*2+1,m+1,r);
	sz[v]=sz[v*2]+sz[v*2+1];
	mer(t[v],t[v*2],t[v*2+1]);
}
void fill2(int v,int id){
	t[v].g=1;
	t[v].a[1]=(no){id,sz[v]};
	ad[v]=id;
}
void dw(int v){
	if(ad[v])fill2(v*2,ad[v]),fill2(v*2+1,ad[v]),ad[v]=0;
}
void fill(int v,int l,int r){
	if(pl<=l&&r<=pr){
		fill2(v,id);
		return;
	}
	dw(v);
	int m=l+r>>1;
	if(pl<=m)fill(v*2,l,m);
	if(m<pr)fill(v*2+1,m+1,r);
	mer(t[v],t[v*2],t[v*2+1]);
}
void qry(int v,int l,int r){
	if(pl<=l&&r<=pr){
		mer(ans,ans,t[v]);
		return;
	}
	dw(v);
	int m=l+r>>1;
	if(pl<=m)qry(v*2,l,m);
	if(m<pr)qry(v*2+1,m+1,r);
}
int main(){
	cin>>n>>m>>p;nd=100/p+1;
	fo(i,1,n)scanf("%d",&a[i]);
	B(1,1,n);
	for(;m--;){
		scanf("%d%d%d",&op,&pl,&pr);
		if(op==1){
			scanf("%d",&id);
			fill(1,1,n);
		}else{
			ans.g=0;
			qry(1,1,n);
			printf("%d ",ans.g);
			fo(i,1,ans.g)printf("%d ",ans.a[i].a);printf("\n");
		}
	}
}