#include <ctime>
#include <random>
#include <cstdio>
#include <algorithm>
const int Maxn=50000;
const int Maxb=1000;
std::mt19937 rnd(time(NULL));
int n,start,x;
int p[Maxn+5];
int v[Maxn+5],nxt[Maxn+5];
void query(int pos){
	if(nxt[pos]!=0){
		return;
	}
	printf("? %d\n",pos);
	fflush(stdout);
	scanf("%d%d",&v[pos],&nxt[pos]);
}
int main(){
	scanf("%d%d%d",&n,&start,&x);
	query(start);
	if(v[start]>=x){
		printf("! %d\n",v[start]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	std::shuffle(p+1,p+1+n,rnd);
	for(int i=1;i<=std::min(n,Maxb);i++){
		query(p[i]);
	}
	int max_pos=start;
	for(int i=1;i<=n;i++){
		if(nxt[i]==0){
			continue;
		}
		if(v[i]>v[max_pos]&&v[i]<=x){
			max_pos=i;
		}
	}
	int ans=max_pos;
	while(v[ans]<x){
		ans=nxt[ans];
		if(ans==-1){
			break;
		}
		query(ans);
	}
	if(ans==-1){
		puts("! -1");
		return 0;
	}
	printf("! %d\n",v[ans]);
	return 0;
}