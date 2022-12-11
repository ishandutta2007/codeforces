#include<iostream>
#include<cstdio>
#include<vector>
#define mid ((l+r)>>1)
using namespace std; 
const int maxn=301000;
int n,q;
int a[maxn];
vector <int> v[maxn];
struct Node{
	int p,c;
	Node(){
		p=c=0;
	}
	Node(int x){
		p=x;c=1;
	}
	Node operator +(Node b)const{
		Node res;
		if(p==b.p)res.p=p,res.c=c+b.c;
		else if(c<b.c)res.p=b.p,res.c=b.c-c;
		else res.p=p,res.c=c-b.c;
		return res;
	}
};
struct Segment_Tree{
	int rt,ver,son[2][maxn<<1];
	Node w[maxn<<1];
	void build(int &p,int l,int r){
		p=++ver;
		if(l==r){
			w[p]=Node(a[l]);return;
		}
		build(son[0][p],l,mid);
		build(son[1][p],mid+1,r);
		w[p]=w[son[0][p]]+w[son[1][p]];
	}
	Node query(int p,int lr,int rr,int l,int r){
		if(lr<=l&&r<=rr)return w[p];
		if(lr>r||l>rr)return Node();
		return query(son[0][p],lr,rr,l,mid)+query(son[1][p],lr,rr,mid+1,r);
	}
}T1;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();q=read();
	for(register int i=1;i<=n;++i){
		a[i]=read();
		v[a[i]].push_back(i);
	}
	T1.build(T1.rt,1,n);
	for(register int i=1,l,r,x;i<=q;++i){
		l=read();r=read();
		Node w=T1.query(T1.rt,l,r,1,n);
		x=lower_bound(v[w.p].begin(),v[w.p].end(),r+1)-lower_bound(v[w.p].begin(),v[w.p].end(),l);
		if(x<=(r-l+2)/2)puts("1");
		else{
			x=1+(x-(r-l+1-x+1));
			printf("%d\n",x);
		}
	}
	return 0;
}