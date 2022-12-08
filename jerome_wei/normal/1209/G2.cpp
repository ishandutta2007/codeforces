#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct dat{
	int mx,mn,ls,rs,ans;
};
dat t[N<<2];
int lzy[N<<2];
void pushup(dat &a,dat b,dat c){
	if(b.mn<c.mn){
		a.mn=b.mn;a.rs=max(b.rs,c.mx);
		a.ls=b.ls;a.ans=b.ans;
	}else if(b.mn>c.mn){
		a.mn=c.mn;a.ls=max(c.ls,b.mx);
		a.rs=c.rs;a.ans=c.ans;
	}else{
		a.mn=b.mn;a.rs=c.rs;
		a.ls=b.ls;a.ans=b.ans+c.ans+max(b.rs,c.ls);
	}
	a.mx=max(b.mx,c.mx);
}
inline void pushdown(int x){
	if(lzy[x]){
		lzy[x<<1]+=lzy[x],t[x<<1].mn+=lzy[x];
		lzy[x<<1|1]+=lzy[x],t[x<<1|1].mn+=lzy[x];
		lzy[x]=0;
	}
}
#define mid ((l+r)>>1)
inline void modify(int x,int l,int r,int ql,int qr,int sum){
	if(ql>qr)return ;
	if(ql<=l&&qr>=r){
		lzy[x] += sum;t[x].mn+=sum;
		return ;
	}
	pushdown(x);
	if(ql<=mid)modify(x<<1,l,mid,ql,qr,sum);
	if(qr>mid)modify(x<<1|1,mid+1,r,ql,qr,sum);
	pushup(t[x],t[x<<1],t[x<<1|1]);
}
inline void add(int x,int l,int r,int pos,int sum){
	if(l==r){
		t[x].ans=t[x].mx=sum;
		return ;
	}
	pushdown(x);
	if(pos<=mid)add(x<<1,l,mid,pos,sum);
	else add(x<<1|1,mid+1,r,pos,sum);
	pushup(t[x],t[x<<1],t[x<<1|1]);
}
#undef mid
set<int> s[N];
int n,q;
inline void del(int x){
	if(s[x].empty())return;
	modify(1,1,n,*s[x].begin(),*s[x].rbegin()-1,-1);
	add(1,1,n,*s[x].begin(),0);
}
inline void ins(int x){
	if(s[x].empty())return;
	modify(1,1,n,*s[x].begin(),*s[x].rbegin()-1,1);
	add(1,1,n,*s[x].begin(),s[x].size());
}
int a[N];
int main()
{
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
	}
	for(int i=1;i<=200000;i++)ins(i);
	printf("%d\n",n-(t[1].ans+t[1].ls+t[1].rs));
	// cout << t[1].ans << " " << t[1].ls << " " << t[1].rs << endl;
	while(q--){
		int pos,x;scanf("%d%d",&pos,&x);
		del(a[pos]);
		s[a[pos]].erase(pos);
		ins(a[pos]);
		a[pos]=x;
		del(a[pos]);
		s[a[pos]].insert(pos);
		ins(a[pos]);
		printf("%d\n",n-(t[1].ans+t[1].ls+t[1].rs));
	}
}