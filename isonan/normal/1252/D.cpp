#include <cstdio>
#include <vector> 

std::vector<std::pair<int,int> >ans;
int t,n,k,pos1[2001],pos2[2001];
char str[2001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&k);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)str[i]=(str[i]=='(');
		ans.clear();
		for(int i=1;i<=(k-1)*2;i++)
			if(str[i]!=(i&1)){
				for(int j=i+1;j<=n;j++)
					if(str[j]==(i&1)){
						std::swap(str[i],str[j]);
						ans.push_back(std::make_pair(i,j));
						break;
					}
			}
		for(int i=(k-1)*2+1;i<=(k-1)*2+((n>>1)-k+1);i++){
			if(!str[i])
				for(int j=i+1;j<=n;j++)
					if(str[j]){
						std::swap(str[i],str[j]);
						ans.push_back(std::make_pair(i,j));
						break;
					}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
}