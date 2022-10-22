#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
const int N=3e5+10;
const LL P=998244353;
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}

void init(){
	return;
}
int n,ans,now,t;
vector<int> A[N],B[N];
struct Node{
	int l,r,id;
}d[N];
bool operator < (Node x,Node y){
	return x.r<y.r;
}
void dfs1(int x){
	d[x].id=x;
	d[x].l=++t;
	for(int i=0;i<B[x].size();++i){
		dfs1(B[x][i]);
	}
	d[x].r=t;
	return;
}
multiset<Node> S;
multiset<Node>::iterator it;
void dfs2(int x){
	int y=0,z=0;
	it=S.lower_bound(d[x]);
	if(it!=S.end()){
		Node tmp=*it;
		if(tmp.l<=d[x].l){
			z=tmp.id;
			S.erase(it);
		}
	}
	y=1;
	it=S.upper_bound(d[x]);
	if(it!=S.begin()){
		--it;
		Node tmp=*it;
		if(tmp.l>=d[x].l){
			y=0;
		}
	}
	if(y==1) S.insert(d[x]);
	if(z) --now;if(y) ++now;
	ans=max(ans,now);
	for(int i=0;i<A[x].size();++i){
		dfs2(A[x][i]);
	}
	if(z) ++now;
	if(y) --now;
	if(y){
		it=S.lower_bound(d[x]);
		S.erase(it);
	}
	if(z){
		S.insert(d[z]);
	}
	return;
}
void MAIN(){
	int u,v;
	scanf("%d",&n);ans=0;now=0;
	for(int i=1;i<=n;++i){
		A[i].clear();B[i].clear();
	}
	for(int i=2;i<=n;++i){
		scanf("%d",&u);
		A[u].push_back(i);
	}
	for(int i=2;i<=n;++i){
		scanf("%d",&u);
		B[u].push_back(i);
	}
	t=0;
	dfs1(1);
	S.clear();
	dfs2(1);
	printf("%d\n",ans);
	return;
}
int main(){
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}