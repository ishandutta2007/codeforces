#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
const int N=3e5+10,M=N*4;
int lim;
struct info{
	int id,cnt;
}ept;
//bool operator <(info a,info b){
//	if (a.tag==b.tag)return a.id<b.id;
//	return a.tag<b.tag;
//}
info tr[M][6];
int n,m,p;
int tag[M],a[N],size[M];
info make(int a,int b){
	return (info){a,b};
}
#define x1 (x+x)
#define x2 (x+x+1)
#define Md (l+r>>1)
typedef set<info>::iterator it;
void add(int x,info a){
	int c1=0,mn=1e9;
	for (int i=0;i<lim;i++){
		c1+=tr[x][i].id>0;
		mn=min(mn,tr[x][i].cnt);
		if (a.id==tr[x][i].id){
			tr[x][i].cnt+=a.cnt;
			return;
		}
	}
	if (c1<lim){
		for (int i=0;i<lim;i++)
			if (tr[x][i].id==0){
				tr[x][i]=a;
				return;
			}
	}
	if (mn<=a.cnt){
		a.cnt-=mn;
		for (int i=0;i<lim;i++){
			tr[x][i].cnt-=mn;
			if (~a.cnt&&!tr[x][i].cnt){
				tr[x][i]=a;
				a.cnt=-1;
			}
		}
	}
	else {
		for (int i=0;i<lim;i++)tr[x][i].cnt-=a.cnt;
	}
}
void update(int x){
	for (int i=0;i<lim;i++)tr[x][i]=tr[x1][i];
	for (auto i:tr[x2])
		add(x,i);
}
void build(int x,int l,int r){
	size[x]=r-l+1;
	if (l==r){
		tr[x][0]=make(a[l],1);
		return;
	}
	build(x1,l,Md);
	build(x2,Md+1,r);
	update(x);
}
void aset(int x,int a){
	tag[x]=a;
	for (int i=1;i<lim;i++)tr[x][i]=ept;
	tr[x][0]=make(a,size[x]);
}
void down(int x){
	if (tag[x]){
		aset(x1,tag[x]);
		aset(x2,tag[x]);
		tag[x]=0;
	}
}
int pl,pr,px;
void modify(int x,int l,int r){
	if (r<pl||pr<l)return;
	if (pl<=l&&r<=pr){
		aset(x,px);
		return;
	}
	down(x);
	modify(x1,l,Md);
	modify(x2,Md+1,r);
	update(x);
}
void query(int x,int l,int r){
	if (r<pl||pr<l)return;
	if (pl<=l&&r<=pr){
		for (auto i:tr[x])
			add(0,i);
		return;
	}
	down(x);
	query(x1,l,Md);
	query(x2,Md+1,r);
}
void write(int x){	
	printf("%d",lim);
	for (int i=0;i<lim;i++)printf(" %d",max(1,tr[x][i].id));
	printf("\n");
}
int read(){
	int w=0;char e=getchar();
	while (!('0'<=e&&e<='9'))e=getchar();
	for (;'0'<=e&&e<='9';e=getchar())w=w*10+e-'0';
	return w;
}
int main(){
	cin>>n>>m>>p;
	lim=100/p;
	for (int i=1;i<=n;i++)a[i]=read();
//	scanf("%d",&a[i]);
	build(1,1,n);
//	for (int i=1;i<=10;i++)write(i);
//	return 0;
	while (m--){
		int ty=read();pl=read(),pr=read();
//		scanf("%d%d%d",&ty,&pl,&pr);
		if (ty==1){
			px=read();
//			scanf("%d",&px);
			modify(1,1,n);
		}
		else {
			for (int i=0;i<lim;i++)tr[0][i]=ept;
			query(1,1,n);
			write(0);
		}
	}
}