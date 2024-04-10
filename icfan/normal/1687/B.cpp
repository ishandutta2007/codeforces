#include <cstdio>
#include <algorithm>
const int Maxm=500;
std::pair<int,int> val[Maxm+5];
int n,m;
bool vis[Maxm+5];
int query_str(){
	printf("? ");
	for(int i=1;i<=m;i++){
		printf("%d",(int)vis[i]);
	}
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int query_id(int id){
	for(int i=1;i<=m;i++){
		vis[i]=0;
	}
	vis[id]=1;
	return query_str();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		val[i]=std::make_pair(query_id(i),i);
	}
	std::sort(val+1,val+1+m,[&](std::pair<int,int> a,std::pair<int,int> b){return a>b;});
	for(int i=1;i<=m;i++){
		vis[i]=1;
	}
	int sum=query_str();
	int ans=0;
	for(int i=1;i<m;i++){
		vis[val[i].second]=0;
		int tmp=query_str();
		if(sum-val[i].first==tmp){
			vis[val[i].second]=1;
			ans+=val[i].first;
		}
		else{
			sum=tmp;
		}
	}
	ans+=val[m].first;
	printf("! %d\n",ans);
	return 0;
}