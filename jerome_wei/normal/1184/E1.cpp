#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int n,m;
struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator < (const edge b)const{return w<b.w;}
}e[N];
int fa[N];
inline int find(int x){
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	int u=find(x),v=find(y);
	if(u==v)return ;
	fa[u]=v;
}
long long sum=0;
inline void setup(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
long long sum2=0;
inline bool judge(int x){
	bool flag=0;
	setup();
	sum2=0;
	for(int i=2;i<=m;i++){
		if(e[i].w >= x&&!flag){
			flag=1;
			if(find(e[1].u)!=find(e[1].v)){
				merge(e[1].u,e[1].v);
				sum2+=x;
			}
		}
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			sum2+=e[i].w;
		}
	}
	if(!flag){
		flag=1;
		if(find(e[1].u)!=find(e[1].v)){
			merge(e[1].u,e[1].v);
			sum2+=x;
		}
	}
	// cout << x << " " << sum2 << " " << sum+x << endl;
	return sum2==sum+x;
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+2,e+m+1);
	setup(),merge(e[1].u,e[1].v);
	for(int i=2;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			sum+=1ll*e[i].w;
		}
	}
	int l=0,r=1000000000;
	while(l<r){
		int mid=(l+r+1)>>1;
		bool res=judge(mid);
		if(res)l=mid;
		else r=mid-1;
	}
	cout << l << endl;
}