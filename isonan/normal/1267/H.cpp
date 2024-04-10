#include <cstdio>
#include <vector>
#include <set>

int t,n;
std::vector<int>vec,tem;
std::set<int>set;
int vis[8501],col[8501];
inline void del(const int &x){vis[x]=-1;}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		vec.resize(n);
		for(int i=0;i<n;i++)scanf("%d",&vec[i]);
		for(int cnt=1;;++cnt){
			if(!vec.size())break;
			for(int i=0;i<vec.size();i++)set.insert(vec[i]);
			for(int i=vec.size()-1;~i;--i){
				if(!vis[vec[i]]){
					vis[vec[i]]=1;
					col[vec[i]]=cnt;
					auto it=set.find(vec[i]);
//					printf("%d %d\n",*set.begin(),*set.rbegin());
					if(vec[i]!=*set.begin())vis[*--it]=-1,++it;
					if(vec[i]!=*set.rbegin())vis[*++it]=-1;
				}
				set.erase(vec[i]);
			}
			tem.clear();
			for(int i=0;i<vec.size();i++){
				if(!~vis[vec[i]])tem.push_back(vec[i]);
				vis[vec[i]]=0;
			}
			vec=tem;
		}
		for(int i=1;i<=n;i++)printf("%d ",col[i]);putchar('\n');
	}
}