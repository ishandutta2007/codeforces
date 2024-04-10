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
const int maxn=1000010;
struct node{
	int son[2],w,lazy;
}tree[maxn*31];
int cnt=1;
int i,j,k,n,m;
void pushdown(int root,int S){
	if(!tree[root].lazy)return;
	tree[ls(root)].lazy^=tree[root].lazy;
	tree[rs(root)].lazy^=tree[root].lazy;
	if(tree[root].lazy&(1<<S))swap(ls(root),rs(root));
	tree[root].lazy=0;
}
void update(int root){
	tree[root].w=tree[ls(root)].w+tree[rs(root)].w;
}
void insert(int &root,int L,int R,int x,int S){
	if(!root)root=++cnt;
	//cout<<"insert "<<root<<' '<<L<<' '<<R<<' '<<x<<' '<<S<<endl;
	if(L==R)tree[root].w++;
	else{
		pushdown(root,S);
		if(x&(1<<S))insert(rs(root),Mid+1,R,x,S-1);
		else insert(ls(root),L,Mid,x,S-1);
		update(root);
	}
}
int find(int root,int L,int R,int l,int r,int S){
	if(!root)return 0;
	//cout<<"finding "<<root<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<S<<endl;
	if(L==l && R==r)return tree[root].w;
	pushdown(root,S);
	if(r<=Mid)return find(ls(root),L,Mid,l,r,S-1);
	else if(l>Mid)return find(rs(root),Mid+1,R,l,r,S-1);
	else return find(ls(root),L,Mid,l,Mid,S-1)+find(rs(root),Mid+1,R,Mid+1,r,S-1);
}
int Root=1;
int main() {
	cin>>n>>m;
	ll ans=0;
	for(i=1;i<=n;i++){
		int x=read();
		tree[1].lazy^=x;
		insert(Root,0,(1<<30)-1,x,29);
		ans+=find(1,0,(1<<30)-1,m,(1<<30)-1,29);
		//cout<<ans<<endl;
	}cout<<ans<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}