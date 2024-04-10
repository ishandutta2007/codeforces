#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct node{
	int val;
	int ls,rs;
	int sum[26];
}tree[2*maxn];
int n,m;
string s;
int root,cnt;
int t[26];
int ans[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void clear(int k){
	tree[k].val=-1;
	tree[k].ls=tree[k].rs=0;
	for(int i=0;i<26;i++)
		tree[k].sum[i]=0;
}
void build(int l,int r){
	int k=++cnt;
	clear(k);
	if(l==r){
		tree[k].sum[s[l]-'a']=1;
		return ;
	}
	int ls,rs;
	int mid=l+((r-l)>>1);
	ls=tree[k].ls=cnt+1; 
	build(l,mid);
	rs=tree[k].rs=cnt+1;
	build(mid+1,r);
	for(int i=0;i<26;i++)
		tree[k].sum[i]=tree[ls].sum[i]+tree[rs].sum[i];
	return ;
}
void add(int k,int l,int r,int co){
	tree[k].val=co;
	for(int i=0;i<26;i++)
		tree[k].sum[i]=0;
	tree[k].sum[co]=r-l+1;
	return ;
}
void pushdown(int k,int l,int r){
	if(tree[k].val==-1)return ;
	int ls=tree[k].ls;
	int rs=tree[k].rs;
	int mid=l+((r-l)>>1);
	add(ls,l,mid,tree[k].val);
	add(rs,mid+1,r,tree[k].val);
	tree[k].val=-1;
	return ;
}
void modify(int k,int l,int r,int x,int y,int val){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){
		add(k,l,r,val);
		return ;
	}
	int ls=tree[k].ls;
	int rs=tree[k].rs;
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	modify(ls,l,mid,x,y,val);
	modify(rs,mid+1,r,x,y,val);
	for(int i=0;i<26;i++)
		tree[k].sum[i]=tree[ls].sum[i]+tree[rs].sum[i];
	return ;
}
int query(int co,int k,int l,int r,int x,int y){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return tree[k].sum[co];
	int ls=tree[k].ls;
	int rs=tree[k].rs;
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	return query(co,ls,l,mid,x,y)+query(co,rs,mid+1,r,x,y);
}
void find_ans(int k,int l,int r){
	if(l==r){
		for(int i=0;i<26;i++){
			if(tree[k].sum[i]==1)
				ans[l]=i+'a';
		}
		return ;
	}
	int ls=tree[k].ls;
	int rs=tree[k].rs;
	int mid=l+((r-l)>>1);
	pushdown(k,l,r);
	find_ans(ls,l,mid);
	find_ans(rs,mid+1,r);
	return ;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();m=read();
	cin>>s;
	s=" "+s;
	root=1;
	build(1,n);
	for(int i=1;i<=m;i++){
		int l,r;
		l=read();r=read();
		int s0=0,s1=0,pos=-1;
		memset(t,0,sizeof(t));
		for(int j=0;j<26;j++){
			t[j]=query(j,root,1,n,l,r);
			s0+=(t[j]%2==0);
			s1+=(t[j]&1);
			if(t[j]&1)pos=j;
		}
		if(s1>1)continue;
		int lt=l,rt=r;
		t[pos]--;
		for(int j=0;j<26;j++){
			if(t[j]==0)continue;
			modify(root,1,n,lt,lt+t[j]/2-1,j);
			modify(root,1,n,rt-t[j]/2+1,rt,j);
			lt+=t[j]/2;rt-=t[j]/2;
		}
		if(pos>-1)
			modify(root,1,n,lt,rt,pos);
	}
	find_ans(root,1,n);
	for(int i=1;i<=n;i++)
		cout<<char(ans[i]);
	return 0;
}