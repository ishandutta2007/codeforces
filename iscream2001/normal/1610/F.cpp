#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;

void init(){
	
}
int n,m,L,R;

int used[N][3],du[N];

struct edge{
	int l,r,col,ls;
}e[N<<2];

int to[N<<2],vis[N],hhh[N<<2];

vector< pair<int,int> > V[N];
void dfs(int x,int fa){
	//cout<<x<<endl;
	if(vis[x]==1) return;
	vis[x]=1;
	for(int i=0,j;i<V[x].size();++i){
		if(V[x][i].second==fa) continue;
		j=V[x][i].second;
		if(e[j].l!=x) swap(e[j].l,e[j].r);
		--du[x];
		--du[V[x][i].first];
		dfs(V[x][i].first,V[x][i].second);
		break;
	}
	return;
}
void MAIN(){
	int u,v,w,id;
	L=1;R=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		e[++R]=(edge){u,v,w,u};
	}
	edge tmp;
	while(L<=R){
		tmp=e[L];
		if(tmp.l==tmp.r){
			to[L]=L;
			L++;continue;
		}
		if(used[tmp.l][tmp.col]!=0){
			id=used[tmp.l][tmp.col];
			e[++R]=(edge){e[id].l^e[id].r^tmp.l,tmp.r,tmp.col,e[id].l^e[id].r^tmp.l};
			to[id]=R;to[L]=R;
			used[tmp.l][tmp.col]=0;
			used[e[id].l^e[id].r^tmp.l][tmp.col]=0;
			L++;continue;
		}
		swap(tmp.l,tmp.r);
		if(used[tmp.l][tmp.col]!=0){
			id=used[tmp.l][tmp.col];
			e[++R]=(edge){e[id].l^e[id].r^tmp.l,tmp.r,tmp.col,e[id].l^e[id].r^tmp.l};
			to[id]=R;to[L]=R;
			used[tmp.l][tmp.col]=0;
			used[e[id].l^e[id].r^tmp.l][tmp.col]=0;
			L++;continue;
		}
		used[tmp.l][tmp.col]=used[tmp.r][tmp.col]=L;
		L++;continue;
	}
	for(int i=1;i<=R;++i){
		if(to[i]==0){
//			cout<<e[i].l<<" "<<e[i].r<<" "<<e[i].col<<endl;
			++du[e[i].l];
			++du[e[i].r];
			V[e[i].l].push_back(make_pair(e[i].r,i));
			V[e[i].r].push_back(make_pair(e[i].l,i));
		}
	}
//for(int i=1;i<=n;++i) cout<<du[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i){
		if(du[i]==1&&vis[i]==0){
			dfs(i,0);
		}
	}
	for(int i=1;i<=n;++i){
		if(du[i]==2&&vis[i]==0){
			dfs(i,0);
		}
	}
	for(int i=R;i>=1;--i){
		if(to[i]==0||to[i]==i) continue;
		if(e[to[i]].l!=e[to[i]].r){
			if(e[i].r==e[to[i]].l) swap(e[i].l,e[i].r);
			if(e[i].l==e[to[i]].r) swap(e[i].l,e[i].r);
		}
		else{
			if(hhh[to[i]]==0){
				if(e[i].r==e[to[i]].l) swap(e[i].l,e[i].r);
			}
			else{
				if(e[i].l==e[to[i]].r) swap(e[i].l,e[i].r);
			}
			hhh[to[i]]=1;
		}
	//	cout<<"now "<<e[i].l<<" "<<e[i].r<<" "<<e[i].col<<endl;
	}
	for(int i=R;i>=1;--i){
		
	//	cout<<"now "<<e[i].l<<" "<<e[i].r<<" "<<e[i].col<<" "<<to[i]<<endl;
	}
	memset(du,0,sizeof(du));
	for(int i=1;i<=m;++i){
		du[e[i].l]-=e[i].col;
		du[e[i].r]+=e[i].col;
	}
//	for(int i=1;i<=n;++i) cout<<du[i]<<" ";cout<<endl;
	int ans=0;
	for(int i=1;i<=n;++i){
		if(du[i]==1||du[i]==-1){
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=m;++i){
		du[e[i].l]-=e[i].col;
		du[e[i].r]+=e[i].col;
		if(e[i].l==e[i].ls){
			putchar('1');
		}
		else{
			putchar('2');
		}
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