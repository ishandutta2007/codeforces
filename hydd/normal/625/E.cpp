#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,m,x[110000],y[110000],lst[110000],nxt[110000],num[110000];
set<pii> s;
set<pii>::iterator it;
bool cmp(int a,int b){ return x[a]<x[b];}
int gettime(int i,int j){
	if (i==j) return INF;
	int d=(x[j]-x[i]+m)%m;
	if (i>j) d=(d+y[j])%m;
	if (d<=y[i]) return 1;
	if (y[i]<=y[j]) return INF;
	return (d-y[j]-1)/(y[i]-y[j])+1;
}
pii makenode(int x){ return pii(gettime(x,nxt[x]),x);}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]--; num[i]=i;
	}
	sort(num+1,num+n+1,cmp);
	for (int i=1;i<n;i++){
		lst[num[i+1]]=num[i];
		nxt[num[i]]=num[i+1];
	}
	lst[num[1]]=num[n]; nxt[num[n]]=num[1];
	for (int i=1;i<=n;i++) s.insert(makenode(i));
	while (!s.empty()){
		if (s.begin()->first==INF) break;
		int u=s.begin()->second;
		s.erase(makenode(lst[u])); s.erase(makenode(u)); s.erase(makenode(nxt[u]));
		x[u]=(x[u]+gettime(u,nxt[u]))%m; y[u]--;
		nxt[u]=nxt[nxt[u]]; lst[nxt[u]]=u;
		s.insert(makenode(lst[u])); s.insert(makenode(u));
	}
	printf("%d\n",s.size());
	for (it=s.begin();it!=s.end();it++) printf("%d ",it->second);
	return 0;
}