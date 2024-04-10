#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=300010;
namespace segment_tree{
	int tree[maxn*4],lazy[maxn*4];
	#define Mid (L+R>>1)
	void pushdown(int root){
		tree[root>>1]+=lazy[root];lazy[root>>1]+=lazy[root];
		tree[root>>1|1]+=lazy[root];lazy[root>>1|1]+=lazy[root];
		lazy[root]=0;
	}
	void update(int root){
		tree[root]=max(tree[root*2],tree[root*2+1]);
	}
	void add(int root,int L,int R,int l,int r,int S){
		if(L==l && R==r){
			lazy[root]+=S;
			tree[root]+=S;
			return;
		}else{
			if(lazy[root])pushdown(root);
			if(r<=Mid)add(root*2,L,Mid,l,r,S);
			else if(l>Mid)add(root*2+1,Mid+1,R,l,r,S);
			else add(root*2,L,Mid,l,Mid,S),add(root*2+1,Mid+1,R,Mid+1,r,S);
			update(root);
		}
	}
	int find(int root,int L,int R,int l,int r){
		if(L==l && R==r)return tree[root];
		else{
			if(lazy[root])pushdown(root);
			if(r<=Mid)return find(root*2,L,Mid,l,r);
			else if(l>Mid)return find(root*2+1,Mid+1,R,l,r);
			else return max(find(root*2,L,Mid,l,Mid),find(root*2+1,Mid+1,R,Mid+1,r));
		}
	}
};
using namespace segment_tree;
int i,j,k,n,m,T,h[maxn],b[maxn],Q[maxn],top,S[maxn],mb[maxn][25],dp[maxn];
signed main(){
	S[1]=0;
	for(i=2;i<maxn;i++)S[i]=S[i/2]+1;
	cin>>n;
	for(i=1;i<=n;i++)h[i]=read();
	for(i=1;i<=n;i++)b[i]=read(),mb[i][0]=b[i];
	for(i=1;i<=20;i++)
		for(j=1;j<=n-(1<<i)+1;j++)
			mb[j][i]=min(mb[j][i-1],mb[j+(1<<i-1)][i-1]);
	Q[top=2]=1;add(1,1,n,1,1,b[1]);
	for(i=2;i<=n;i++){
		int last=i-1;
		dp[i]=find(1,1,n,1,i-1);
//		cout<<"dp["<<i<<"]="<<dp[i]<<endl;
		while(top){
//			cout<<i<<' '<<Q[top]<<endl;
			if(h[Q[top]]>h[i]){
				int S=b[Q[top]];
				top--;
				int nxt=Q[top]+1;
				add(1,1,n,nxt,last,b[i]-S);
				last=nxt-1;
			}else break;
		}Q[++top]=i;
		add(1,1,n,i,i,dp[i]+b[i]);
	}cout<<find(1,1,n,1,n)<<endl;
	return 0;
}