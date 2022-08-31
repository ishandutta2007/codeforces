#include <cstdio>
#include <vector>

int n,c[200001],stk[200001],top;
bool vis[200001],bel[200001];
std::vector<std::pair<int,int> >ans;
std::vector<std::vector<int> >par;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			int tem=i;
			top=0;
			while(!vis[tem]){
				vis[tem]=1;
				stk[++top]=tem;
				tem=c[tem];
			}
			std::vector<int>now;
			for(int i=1;i<=top;i++)now.push_back(stk[i]);
			if(now.size()>1)par.push_back(now);
		}
	while(par.size()>=2){
		auto p1=par.back();
		par.pop_back();
		auto p2=par.back();
		par.pop_back();
		ans.push_back(std::make_pair(p1[0],p2[0]));
		for(int i=1;i<p1.size();++i)ans.push_back(std::make_pair(p1[i],p2[0]));
		for(int i=1;i<p2.size();++i)ans.push_back(std::make_pair(p2[i],p1[0]));
		ans.push_back(std::make_pair(p1[0],p2[0]));
	}
	if(par.size()==1){
		std::vector<int>now=par[0];
		if(now.size()==2){
			int p=1;
			while(p==now[0]||p==now[1])++p;
			ans.push_back(std::make_pair(now[0],p));
			ans.push_back(std::make_pair(now[1],p));
			ans.push_back(std::make_pair(now[0],p));
		}
		else{
			for(int i=0;i<now.size();++i)stk[i+1]=now[i];
			top=now.size();
				ans.push_back(std::make_pair(stk[1],stk[2]));
				for(int i=3;i<top;++i)ans.push_back(std::make_pair(stk[1],stk[i]));
				ans.push_back(std::make_pair(stk[2],stk[top]));
				ans.push_back(std::make_pair(stk[1],stk[top]));
				ans.push_back(std::make_pair(stk[1],stk[2]));
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i)printf("%d %d\n",ans[i].first,ans[i].second);
}