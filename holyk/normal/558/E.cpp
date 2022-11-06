#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c;int w;
	while(!isdigit(c=getchar()));w=c&15;
	while(isdigit(c=getchar()))w=w*10+(c&15);return w;
}
inline char smax(int&x,const int&y){return x<y?x=y,1:0;}
inline char smin(int&x,const int&y){return x>y?x=y,1:0;}
const int N=1e5+5;
struct node{
	int ls,rs,w,ch;
}t[N*120];
int rt[26],cnt;
inline void add(int&o,int w,int len){if(!o)o=++cnt;t[o].ch=w,t[o].w=len*w;}
inline void pushdown(int&o,int len){
	if(~t[o].ch){
		add(t[o].ls,t[o].ch,len-(len>>1));
		add(t[o].rs,t[o].ch,len>>1);
		t[o].ch=-1;
	}
}
inline void pushup(int o){t[o].w=t[t[o].ls].w+t[t[o].rs].w;}
inline void update(int&o,int l,int r,int x,int y){
	pushdown(o,r-l+1);
	if(x<=l&&r<=y)return add(o,1,r-l+1);
	if(!o)t[o=++cnt].ch=-1;int mid=l+r>>1;
	if(x<=mid)update(t[o].ls,l,mid,x,y);if(y>mid)update(t[o].rs,mid+1,r,x,y);
	pushup(o);
}
inline void ins(int&o,int l,int r,int x){
	if(!o)t[o=++cnt].ch=-1;++t[o].w;
	if(l==r)return;int mid=l+r>>1;
	x<=mid?ins(t[o].ls,l,mid,x):ins(t[o].rs,mid+1,r,x);
}
inline int query(int&o,int l,int r,int x,int y){
	if(!o||x>r||y<l)return 0;pushdown(o,r-l+1);
	if(x<=l&&r<=y){int ans=t[o].w;return t[o].w=t[o].ch=0,ans;}
	int mid=l+r>>1,ans=query(t[o].ls,l,mid,x,y)+query(t[o].rs,mid+1,r,x,y);
	return pushup(o),ans;
}
char s[N];
int c[26];
int main(){
	int n=read(),q=read();		
	scanf("%s",s+1);
	REP(i,1,n)ins(rt[s[i]-'a'],1,n,i);
	while(q--){
		int l=read(),r=read(),op=read();
		REP(i,0,25)c[i]=query(rt[i],1,n,l,r);
		if(op){
			int p=l;
			REP(i,0,25)if(c[i])update(rt[i],1,n,p,p+c[i]-1),p+=c[i];
		}
		else{
			int p=r;
			REP(i,0,25)if(c[i])update(rt[i],1,n,p-c[i]+1,p),p-=c[i];
		}
	}
	REP(i,1,n)REP(j,0,25)if(query(rt[j],1,n,i,i)){putchar(j+'a');break;}
	
	return 0;
}