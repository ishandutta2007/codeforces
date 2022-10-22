#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=5e5+10;

void init(){
}
int n,m;
struct edge{
	int r,id;
};
vector< edge > V[1000005];

int vis[1000005];

int it[1000005],circnt=0;

struct Circuit{
	int nxt,val,id;
}cir[1000005];

int GetCircuit(int now){
	int x=cir[now].val,y,z;
	while(it[x]<V[x].size()&&vis[V[x][it[x]].id]) ++it[x];
	if(it[x]<V[x].size()){
		cir[++circnt]=(Circuit){0,V[x][it[x]].r,0};
		cir[now].nxt=circnt;
		cir[now].id=V[x][it[x]].id;
		vis[V[x][it[x]].id]=1;
		it[x]++;
		return GetCircuit(circnt);
	}
	else{
		return now;
	}
}

int EulerCircuit1(int hed){
	//
	//
	// 
	circnt=1;
	cir[1]=(Circuit){0,hed,0};
	int now=1,x,y,z,nnt,iid;
	while(now){
		x=cir[now].val;
		while(it[x]<V[x].size()&&vis[V[x][it[x]].id]==1) ++it[x];
		if(it[x]<V[x].size()){
			nnt=cir[now].nxt;
			iid=cir[now].id;
			cir[++circnt]=(Circuit){0,V[x][it[x]].r,0};
			cir[now].nxt=circnt;
			cir[now].id=V[x][it[x]].id;
			vis[V[x][it[x]].id]=1;
			it[x]++;
			z=GetCircuit(circnt);
			cir[z].nxt=nnt;
			cir[z].id=iid;
		}
		else {
			now=cir[now].nxt;
		}
	}
	return 1;
}

int du[400005];

int ans[400005];

void MAIN(){
	int u,v,now;
	scanf("%d",&m);n=400001;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		v+=200000;
		++du[u];
		++du[v];
		V[u].push_back((edge){v,i});
		V[v].push_back((edge){u,i});
	}
//	cout<<"?"<<endl;
	now=m;
	for(int i=1;i<=400000;++i){
		if(du[i]&1){
			++now;
			V[i].push_back((edge){n,now});
			V[n].push_back((edge){i,now});
		}
	}
//	cout<<"?"<<endl;
	for(int i=1;i<=400000;++i){
		if(V[i].size()==0) continue;
		if(it[i]==0){
			now=EulerCircuit1(i);
			while(cir[now].nxt){
				ans[cir[now].id]=(cir[now].val<=200000)?0:1;
				now=cir[now].nxt;
			}
		}
	}
	for(int i=1;i<=m;++i){
		putchar(ans[i]?'r':'b');
	}
	puts("");
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}