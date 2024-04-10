#include <cstdio>
#include <vector>
#include <algorithm>

int t;
int n,a[100010];
bool vis[100010];
struct array{
	int a[100010],pre[100010],ord[100010],f[100010];
	int stk[100010],top;
	void init(){
		for(int i=1;i<=n;i++)ord[a[i]]=i;
	}
	std::vector<int> getans(){
		top=0;
		int p=0;
		for(int i=1;i<=n;i++){
			pre[i]=0;
			if(vis[i])continue;
			if(stk[top]<a[i]||!top){
				pre[i]=ord[stk[top]];
				stk[++top]=a[i];
				p=i;
				f[i]=top;
			}
			else{
				int u=std::lower_bound(stk+1,stk+top+1,a[i])-stk;
				pre[i]=ord[stk[u-1]];
				f[i]=u;
				stk[u]=a[i];
			}
		}
//		for(int i=1;i<=top;i++)printf("%d ",stk[i]);putchar('\n');
//		for(int i=1;i<=n;i++)printf("%d ",pre[i]);putchar('\n');
		std::vector<int>ans;
		for(;p;){
			ans.push_back(p);
			p=pre[p];
		}
		std::reverse(ans.begin(),ans.end());
		return ans;
	}
}orig;
std::vector<std::vector<int> >ans;
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i),orig.a[i]=a[i],vis[i]=0;
		orig.init();
		ans.resize(0);
		for(int cnt=0;;){
//			printf("%d\n",cnt);
			std::vector<int>v1=orig.getans();
//			printf("%d\n",v1.size());
			if(2*(n-cnt)/v1.size()>v1.size()+1){
				int nowsiz=ans.size()-1;
				ans.resize(ans.size()+v1.size());
				for(int i=1;i<=n;i++)
					if(!vis[i])ans[nowsiz+orig.f[i]].push_back(i);
				break;
			}
			else{
				cnt+=v1.size();
				for(int i=0;i<v1.size();i++)vis[v1[i]]=1;
				ans.push_back(v1);
			}
			if(cnt==n)break;
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++,putchar('\n')){
			printf("%d ",ans[i].size());
			for(int j=0;j<ans[i].size();j++)
				printf("%d ",a[ans[i][j]]);
		}
	}
}