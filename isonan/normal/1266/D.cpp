#include <cstdio>
#include <vector>

#define int long long
int n,m,head[100001],nxt[600001],b[600001],k;
long long d[100001];
std::vector<std::pair<int,int> >pos,neg;
long long ans[300001][3],top;
void add(int s,int t,long long v){
	++top;
	ans[top][0]=s;
	ans[top][1]=t;
	ans[top][2]=v;
}
signed main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1,u,v,val;i<=m;i++)scanf("%I64d%I64d%I64d",&u,&v,&val),d[u]+=val,d[v]-=val;
	for(int i=1;i<=n;i++)if(d[i]>0ll)pos.push_back(std::make_pair(d[i],i));else if(d[i]<0ll)neg.push_back(std::make_pair(-d[i],i));
	for(int i=0;i<pos.size();i++){
			while(neg.back().first){
				int v=std::min(pos[i].first,neg.back().first);
				add(pos[i].second,neg.back().second,std::min(pos[i].first,neg.back().first));
				if(neg.back().first==v)neg.pop_back();
				else neg.back().first-=v;
				pos[i].first-=v;
				if(!pos[i].first)break;
			}
	}
	printf("%I64d\n",top);
	for(int i=1;i<=top;i++)printf("%I64d %I64d %I64d\n",ans[i][0],ans[i][1],ans[i][2]);
}