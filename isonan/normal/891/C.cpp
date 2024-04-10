#include <algorithm>
#include <cstdio>
#include <map>

int cnt,u[500001],v[500001],now,f[1000001],n,m,T[1000001],q,k,x;
std::map<int,int>map;
struct edge{int u,v,val,ord;}num[500001];
bool cmp(edge a,edge b){return a.val<b.val;}
int find(int x){return T[x]==now?(f[x]?f[x]=find(f[x]):x):(T[x]=now,f[x]=0,x);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&num[i].u,&num[i].v,&num[i].val);
		num[i].ord=i;
	}
	std::sort(num+1,num+m+1,cmp);
	int last=1;
	for(int i=1;i<=m;i++){
		if(num[i].val!=num[i-1].val){
			for(int j=last;j<i;j++){
				num[j].v=find(num[j].v);
				num[j].u=find(num[j].u);
				if(num[j].v!=num[j].u)f[num[j].v]=num[j].u;
			}
			last=i,map.clear();
		}
		num[i].u=find(num[i].u),u[num[i].ord]=map.count(num[i].u)?map[num[i].u]:map[num[i].u]=++cnt;
		num[i].v=find(num[i].v),v[num[i].ord]=map.count(num[i].v)?map[num[i].v]:map[num[i].v]=++cnt;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		++now;
		scanf("%d",&k);
		bool cando=1;
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			int t1=find(u[x]),t2=find(v[x]);
			if(t1==t2)cando=0;
			else f[t1]=t2;
		}
		puts(cando?"YES":"NO"); 
	}
}