#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::pair<int,int> >e[500001];
int cnt,f[1000001],rank[1000001],stk[2000001][3],top;
std::map<std::pair<int,int>,int>map;
int n,m,k,c[500001];
bool bad[500001];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int find(int x){return f[x]?find(f[x]):x;}
void merge(int u,int v){
	if(rank[u]>rank[v])std::swap(u,v);
	++top;
	stk[top][0]=u;
	stk[top][1]=v;
	stk[top][2]=rank[v];
	rank[v]=std::max(rank[v],rank[u]+1);
	f[u]=v;
}
void rollback(){
	f[stk[top][0]]=0;
	rank[stk[top][1]]=stk[top][2];
	--top;
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		if(c[u]>c[v])std::swap(u,v);
		int &p=map[std::make_pair(c[u],c[v])];
		if(!p)p=++cnt;
		e[p].push_back(std::make_pair(u,v));
	}
	int r=k;
	for(int i=1;i<=k;i++)
		if(map.count(std::make_pair(i,i))){
			int p=map[std::make_pair(i,i)];
			for(int j=0;j<e[p].size();j++){
				int u=e[p][j].first,v=e[p][j].second;
				int fu=find(u),fv=find(v+n);
				if(fu!=fv)merge(fu,fv);
				fu=find(u+n),fv=find(v);
				if(fu!=fv)merge(fu,fv);
				if(find(u)==find(v)&&!bad[i])
					bad[i]=1,--r;
			}
			map.erase(std::make_pair(i,i));
		}
	long long ans=(1ll*r*(r-1))>>1ll;
	for(std::map<std::pair<int,int>,int>::iterator it=map.begin();it!=map.end();++it){
		if(bad[it->first.first]||bad[it->first.second])continue;
		int last=top;
		int p=it->second;
		bool bad=0;
		for(int j=0;j<e[p].size();j++){
			int u=e[p][j].first,v=e[p][j].second;
			int fu=find(u),fv=find(v+n);
			if(fu!=fv)merge(fu,fv);
			fu=find(u+n),fv=find(v);
			if(fu!=fv)merge(fu,fv);
			if(find(u)==find(v)&&!bad){
				bad=1,--ans;
				break;
			}
		}
		while(top>last)rollback();
	}
	printf("%lld\n",ans);
}