#include<bits/stdc++.h>

using namespace std;
#define LL long long
const int N=3e5+10;
const LL INF=1e18;
const LL P=998244353;
LL add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
int n,m,K;
struct Node{
	int id;
	int v;
};

bool operator < (Node x,Node y){
	if(x.v!=y.v)return x.v>y.v;
	else return x.id>y.id;
}
priority_queue<Node>Q;
int ans[N];
void MAIN(){
	Node tmp;
	scanf("%d%d%d",&n,&m,&K);
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=m;++i){
		tmp.id=i;tmp.v=0;
		Q.push(tmp);
	}
	int u,v;
	for(int i=1;i<=n;++i){
		scanf("%d",&u);
		tmp=Q.top();Q.pop();
		tmp.v+=u;ans[i]=tmp.id;
		Q.push(tmp);
	}
	puts("YES");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	puts("");
	return;
}

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}