#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC option("arch=native","tune=native","no-zero-upper")

#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,match[300005];
string S;
vector<int> sk;
vector<int> nxt[300005];

const int e[2]={31,53},mod[2]={1000000007,1000000009};
int pw[2][300005];

/*int tot=1,pos[200005],fa2[1200005];
int ch[1200005][2];

int rt=2;
int lc[1200005],rc[1200005],fa[1200005],sz[1200005];
void pushup(int x)
{
	sz[x]=1;
	if(lc[x]) sz[x]+=sz[lc[x]];
	if(rc[x]) sz[x]+=sz[rc[x]];
}
void rot(int x)
{
	int y=fa[x],z=fa[y];
	if(z){if(lc[z]==y)lc[z]=x; else rc[z]=x;}
	fa[x]=z;fa[y]=x;
	if(lc[y]==x){if(lc[y]=rc[x])fa[lc[y]]=y;rc[x]=y;}
	else{if(rc[y]=lc[x])fa[rc[y]]=y;lc[x]=y;}
	pushup(y);pushup(x);
}
void splay(int x)
{
	while(fa[x])
	{
		int y=fa[x],z=fa[y];
		if(z)
		{
			if((lc[z]==y)==(lc[y]==x)) rot(y); else rot(x);
		}
		rot(x);
	}
	rt=x;
}

int ext(int ori,int c)
{
	if(ch[ori][c]) return ch[ori][c];
	
	ch[ori][c]=++tot;
	fa2[tot]=ori;
	
	if(c==0)
	{
		splay(ori*2-1);
		rc[tot*2]=rc[ori*2-1];
		rc[tot*2-1]=tot*2;
		rc[ori*2-1]=tot*2-1;
		pushup(tot*2);
		pushup(tot*2-1);
	}
	else
	{
		splay(ori*2);
		lc[tot*2-1]=lc[ori*2];
		lc[tot*2]=tot*2-1;
		lc[ori*2]=tot*2;
		pushup(tot*2-1);
		pushup(tot*2);
	}
	
	return tot;
}

int getrnk(int x)
{
	splay(x);
	return sz[lc[x]];
}

bool cmp(int x,int y)
{
	return getrnk(x*2-1)<getrnk(y*2-1);
}

void upd(int x,int y)
{
	if(pos[x]==0||cmp(y,pos[x])) pos[x]=y;
}*/


int pos[300005],tot;
int lc[12000005],rc[12000005];
struct sta
{
	int h[2],sz;
}T[12000005];
sta operator +(sta a,sta b)
{
	sta c;
	c.h[0]=(1ll*b.h[0]*pw[0][a.sz]+a.h[0])%mod[0];
	c.h[1]=(1ll*b.h[1]*pw[1][a.sz]+a.h[1])%mod[1];
	c.sz=a.sz+b.sz;
	return c;
}

void update(int &x,int l,int r,int p,int c)
{
	tot++;
	lc[tot]=lc[x];rc[tot]=rc[x];
	T[tot]=T[x];x=tot;
	if(l==r)
	{
		T[tot].sz=1;T[tot].h[0]=T[tot].h[1]=c;
		return;
	}
	
	int mid=(l+r)/2;
	if(p<=mid) update(lc[x],l,mid,p,c); else update(rc[x],mid+1,r,p,c);
	T[x]=T[lc[x]]+T[rc[x]];
}

sta query(int x,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return T[x];
	int mid=(l+r)/2;
	if(R<=mid) return query(lc[x],l,mid,L,R);
	if(L>mid) return query(rc[x],mid+1,r,L,R);
	return query(lc[x],l,mid,L,mid)+query(rc[x],mid+1,r,mid+1,R);
}

int query2(int x,int l,int r,int p)
{
	if(l==r) return T[x].h[0];
	int mid=(l+r)/2;
	if(p<=mid) return query2(lc[x],l,mid,p);else return query2(rc[x],mid+1,r,p);
}

void print(int x,int l,int r)
{
	if(!T[x].sz) return;
	if(l==r) {putchar(T[x].h[0]?')':'(');return;}
	
	print(rc[x],(l+r)/2+1,r);
	print(lc[x],l,(l+r)/2);
}

int ext(int x,int y)
{
	int t=x;
	update(t,1,n,T[x].sz+1,y);
	return t;
}

bool cmp(int x,int y)
{
	int l=1,r=min(T[x].sz,T[y].sz)+1,mid,lcp=0;
	while(l<r)
	{
		mid=(l+r)/2;
		sta a=query(x,1,n,T[x].sz-mid+1,T[x].sz);
		sta b=query(y,1,n,T[y].sz-mid+1,T[y].sz);
		if(a.h[0]==b.h[0]&&a.h[1]==b.h[1])
		{
			l=mid+1;
			lcp=mid;
		}
		else r=mid;
	}
	
	if(lcp==min(T[x].sz,T[y].sz)) return T[x].sz<T[y].sz;
	return query2(x,1,n,T[x].sz-lcp)<query2(y,1,n,T[y].sz-lcp);
}
void upd(int x,int y)
{
	if(pos[x]==-1||cmp(y,pos[x])) pos[x]=y;
}

int main()
{
	int i;
	cin>>S;
	n=S.size();
	S=" "+S;
	
	rep(i,n)
	{
		if(S[i]=='(') sk.push_back(i);
		else if(!sk.empty())
		{
			match[sk.back()]=i;
			match[i]=sk.back();
			sk.pop_back();
		}
	}
	
	
	pw[0][0]=pw[1][0]=1;
	rep(i,n)
	{
		pw[0][i]=1ll*pw[0][i-1]*e[0]%mod[0];
		pw[1][i]=1ll*pw[1][i-1]*e[1]%mod[1];
	}
	
	
/*	rc[1]=2;
	pushup(2);
	pushup(1);
	pos[n+1]=1;*/
	
	pos[n+1]=0;
	rep(i,n) pos[i]=-1;
	
	
	per(i,n)
	{
//		print(pos[i+1],1,n);
//		puts("");
		
		upd(i,ext(pos[i+1],S[i]=='('?0:1));
		if(S[i]==')'&&(i==n||S[i+1]!=')')&&match[i]) upd(match[i],pos[i+1]);
	}
	
	print(pos[1],1,n);
	puts("");
	
/*	vector<int> ans;
	int tmp=pos[1];
	while(tmp!=1)
	{
		ans.push_back(ch[fa2[tmp]][1]==tmp);
		tmp=fa2[tmp];
	}
	
	for(i=ans.size()-1;i>=0;i--) putchar(ans[i]?')':'(');*/
	
	return 0;
}