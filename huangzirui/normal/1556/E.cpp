#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn],S[maxn],c[maxn],tree[maxn][4],Mx[maxn*2][21][2],LN[maxn*2],tmp[maxn];
int lowbit(int x){
	return x&(-x);
}
int find(int x,int b){
	int ans=0;for(;x;x-=lowbit(x))ans+=tree[x][b];return ans;
}
void add(int x,int s,int b){
	for(;x<=n;x+=lowbit(x))tree[x][b]+=s;
}
struct query{
	int l,r,id;
}Q[maxn];
bool cmp(query a,query b){
	return a.l>b.l;
}
namespace segment_tree{
	#define Mid ((L+R)/2)
	int Max[maxn*4][2],lazy[maxn*4][2],tree[maxn*4][2];
	void pushdown(int root,int b){
		lazy[root*2][b]+=lazy[root][b];
		tree[root*2][b]+=lazy[root][b];
//		Max[root*2][b]=max(Max[root*2][b],tree[root*2][b]);
		lazy[root*2+1][b]+=lazy[root][b];
		tree[root*2+1][b]+=lazy[root][b];
//		Max[root*2+1][b]=max(Max[root*2+1][b],tree[root*2+1][b]);
		lazy[root][b]=0;
	}
	void update(int root,int b){
		tree[root][b]=max(tree[root*2][b],tree[root*2+1][b]);
//		Max[root][b]=max(Max[root*2][b],Max[root*2+1][b]);
	}
	void add(int root,int L,int R,int l,int r,int s,int b){
		if(L==l && R==r)lazy[root][b]+=s,tree[root][b]+=s/*,Max[root][b]=max(Max[root][b],tree[root][b])*/;
		else{
			pushdown(root,b);
			if(r<=Mid)add(root*2,L,Mid,l,r,s,b);
			else if(l>Mid)add(root*2+1,Mid+1,R,l,r,s,b);
			else add(root*2,L,Mid,l,Mid,s,b),add(root*2+1,Mid+1,R,Mid+1,r,s,b);
			update(root,b);
		}
	}
	int findMax(int root,int L,int R,int l,int r,int b){
		if(L==l && R==r)return tree[root][b];
		else{
			pushdown(root,b);
			if(r<=Mid)return findMax(root*2,L,Mid,l,r,b);
			else if(l>Mid)return findMax(root*2+1,Mid+1,R,l,r,b);
			else return max(findMax(root*2,L,Mid,l,Mid,b),findMax(root*2+1,Mid+1,R,Mid+1,r,b));
		}
	}
}using namespace segment_tree;
signed main(){
	cin>>n>>m;
	LN[0]=-1;for(i=1;i<=n;i++)LN[i]=LN[i/2]+1;
	for(i=1;i<=n;i++)
		a[i]=read();
	for(i=1;i<=n;i++)
		a[i]-=read();
	for(i=1;i<=n;i++)
		c[i]=(a[i]>0),a[i]=abs(a[i]),Mx[i][0][c[i]]=a[i];
	for(i=1;i<=n;i++)
		add(i,a[i],c[i]);
	for(i=1;i<=20;i++)
		for(j=1;j<=n;j++){
			if(j+(1<<i)>n)break;
			Mx[j][i][0]=max(Mx[j][i-1][0],Mx[j+(1<<i-1)][i-1][0]),
			Mx[j][i][1]=max(Mx[j][i-1][1],Mx[j+(1<<i-1)][i-1][1]);
		}
	for(i=1;i<=m;i++){
		int l=read(),r=read();
		Q[i]={l,r,i};
	}
	sort(Q+1,Q+1+m,cmp);
	int lastl=n+1;
	for(i=1;i<=m;i++){
		int l=Q[i].l,r=Q[i].r;
		while(lastl!=l){
			lastl--;
//			cout<<lastl<<' '<<n<<' '<<a[lastl]<<' '<<c[lastl]<<endl;
			add(1,1,n,lastl,n,a[lastl],c[lastl]);
			add(1,1,n,lastl,n,-a[lastl],1-c[lastl]);
		}
		if(find(r,0)-find(l-1,0)!=find(r,1)-find(l-1,1))tmp[Q[i].id]=-1;
		else{
			int len=LN[r-l+1];
			tmp[Q[i].id]=max(findMax(1,1,n,l,r,0),findMax(1,1,n,l,r,1));
		}
	}for(i=1;i<=m;i++)printf("%lld\n",tmp[i]);
	return 0;
}