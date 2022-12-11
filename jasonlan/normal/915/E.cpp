#include<iostream>
#include<cstdio>
#include<set>
#define IT set<node>::iterator
using namespace std;
int n,q,ans;
struct node{
	int l,r,v;
	node(){}
	node(int a,int b,int c){l=a;r=b;v=c;}
	bool operator <(node b)const{
		return l<b.l;
	}
};
set<node> s;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
IT split(int pos){
	IT p=s.lower_bound(node(pos,0,0));
	if(p!=s.end()&&p->l==pos)return p;
	p--;
	int L=p->l,R=p->r,V=p->v;
	s.erase(p);
	s.insert(node(L,pos-1,V));
	return s.insert(node(pos,R,V)).first;
}
void cover(int l,int r,int op){
	IT rp=split(r+1),lp=split(l),p;
	for(IT p=lp;p!=rp;p++)
		if(p->v)ans-=p->r-p->l+1;
	s.erase(lp,rp);
	s.insert(node(l,r,op));
	if(op)ans+=(r-l+1);
}
int main(){
	n=read();q=read();
	ans=n;
	s.insert(node(1,n,1));
	s.insert(node(n+1,n+1,0)); 
	for(register int i=0,l,r,op;i<q;++i){
		l=read();r=read();op=read();
		cover(l,r,(op&2)>>1);
		printf("%d\n",ans);
	}
	return 0;
}