#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct bian{
	int next,point;
	long long w;
}b[210000];
long long d[210000];
int p[110000],n,m,q,len,dis[110000];
struct atom{
	int where;
	long long w;
};
int operator < (const atom k1,const atom k2){
	return k1.w>k2.w;
}
priority_queue<atom>Q;
void ade(int k1,int k2,int k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void firget(){
	memset(d,0x3f,sizeof d); d[1]=0; Q.push((atom){1,0});
	while (!Q.empty()){
		atom k=Q.top(); Q.pop();
		if (d[k.where]!=k.w) continue;
		for (int i=p[k.where];i;i=b[i].next){
			int j=b[i].point;
			if (d[j]>k.w+b[i].w){
				d[j]=k.w+b[i].w; Q.push((atom){j,d[j]});
			}
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			b[i].w=b[i].w-(d[j]-d[k]);
		}
}
vector<int>A[110000];
void recalc(){
	for (int i=0;i<=n;i++) A[i].clear();
	memset(dis,0x3f,sizeof dis);
	dis[1]=0; A[0].push_back(1);
	for (int nowdis=0;nowdis<=n;nowdis++)
		for (int where=0;where<A[nowdis].size();where++){
			int k=A[nowdis][where];
			if (dis[k]!=nowdis) continue;
			for (int i=p[k];i;i=b[i].next){
				int j=b[i].point;
				if (dis[j]>dis[k]+b[i].w){
					dis[j]=dis[k]+b[i].w;
					if (dis[j]<=n) A[dis[j]].push_back(j);
				}
			}
		}
	for (int i=1;i<=n;i++) d[i]+=dis[i];
	for (int k=1;k<=n;k++)
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			b[i].w=b[i].w-(dis[j]-dis[k]);
		}
}
int main(){
	scanf("%d%d%d",&n,&m,&q); 
	//n=100000; m=100000; q=2000;
	for (int i=1;i<=m;i++){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); 
		//k1=1; k2=i; k3=rand()%1000000000+1;
		ade(k1,k2,k3);
		//k1=rand()%n+1; k2=rand()%n+1; k3=rand()%m+1;
	}
	firget();
	//for (int i=1;i<=n;i++) cout<<d[i]<<" "; cout<<endl;
	//for (int i=1;i<=m;i++) cout<<b[i].w<<" "; cout<<endl;
	for (;q;q--){
		int k1; k1=2; scanf("%d",&k1);
		if (k1==1){
			int k2; scanf("%d",&k2); 
			if (d[k2]>1e18) printf("-1\n"); else printf("%I64d\n",d[k2]);
		} else {
			int k2; k2=500; scanf("%d",&k2);
			for (int i=1;i<=k2;i++){
				int k3=1; scanf("%d",&k3);
				b[k3].w++;
			}
			recalc();
		}
	}
	return 0;
}