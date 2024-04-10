#include <bits/stdc++.h>
#define ls(x) tree[x].son[0]
#define rs(x) tree[x].son[1]
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=200010;
int i,j,k,n,m,N,a[maxn],block[maxn],size[maxn];
namespace segment_tree{
	struct tr{
		int w,son[2];
	}tree[maxn*8];
	int cnt;
	void update(int root){
		tree[root].w=tree[ls(root)].w+tree[rs(root)].w;
	}
	void add(int &root,int L,int R,int x,int s){
		if(!root)root=++cnt;
		if(L==R)tree[root].w+=s;
		else{
			if(x<=Mid)add(ls(root),L,Mid,x,s);
			else add(rs(root),Mid+1,R,x,s);
			update(root);
		}
	}
	int find(int root,int L,int R,int l,int r){
		if(!root)return 0;
		if(L==l && R==r)return tree[root].w;
		else{
			if(r<=Mid)return find(ls(root),L,Mid,l,r);
			else if(l>Mid)return find(rs(root),Mid+1,R,l,r);
			else return find(ls(root),L,Mid,l,Mid)+find(rs(root),Mid+1,R,Mid+1,r);
		}
	}
};using namespace segment_tree;
int Root[maxn];
int main() {
	cin>>n>>m;N=sqrt(n);
	for(i=1;i<=n;i++){
		a[i]=i;
		size[block[i]=(i-1)/N+1]++;
		add(Root[block[i]],1,n,a[i],1);
	}ll ans=0;
	for(i=1;i<=m;i++){
		int x=read(),y=read();
		if(x>y)swap(x,y);
		if(x!=y){
			if(block[x]==block[y]){
				for(j=x+1;j<=y-1;j++)
					if(a[x]<=a[j] && a[j]<=a[y])ans+=2;
					else if(a[x]>=a[j] && a[j]>=a[y])ans-=2;
				ans+=(a[x]<a[y]? 1:-1);
				add(Root[block[x]],1,n,a[x],-1);
				add(Root[block[y]],1,n,a[y],-1);
				add(Root[block[y]],1,n,a[x],1);
				add(Root[block[x]],1,n,a[y],1);
				swap(a[x],a[y]);
			}
			else{
				for(j=x+1;block[j]==block[x];j++)
					if(a[x]<=a[j] && a[j]<=a[y])ans+=2;
					else if(a[x]>=a[j] && a[j]>=a[y])ans-=2;
				for(j=y-1;block[j]==block[y];j--)
					if(a[x]<=a[j] && a[j]<=a[y])ans+=2;
					else if(a[x]>=a[j] && a[j]>=a[y])ans-=2;
				for(j=block[x]+1;j<=block[y]-1;j++){
					if(a[x]<a[y])ans+=find(Root[j],1,n,a[x],a[y])*2;
					else ans-=find(Root[j],1,n,a[y],a[x])*2;
				}
				ans+=(a[x]<a[y]? 1:-1);
				add(Root[block[x]],1,n,a[x],-1);
				add(Root[block[y]],1,n,a[y],-1);
				add(Root[block[y]],1,n,a[x],1);
				add(Root[block[x]],1,n,a[y],1);
				swap(a[x],a[y]);
			}
		}printf("%lld\n",ans);
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}