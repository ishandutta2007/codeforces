#include <cstdio>
#include <vector>

int n;
int ans[110][110];
std::vector<std::pair<int,int> >vec[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			vec[(i+j)&1].push_back(std::make_pair(i,j));
	for(int i=1,a;i<=n*n;++i){
		scanf("%d",&a);
		int x,y,v;
		if(a!=1){
			if(vec[0].empty()){
				x=vec[1].back().first,y=vec[1].back().second;
				vec[1].pop_back();
				v=1;
				if(ans[x-1][y]==1||ans[x+1][y]==1||ans[x][y-1]==1||ans[x][y+1]==1)
					v=2+(a==2);
			}
			else{
				x=vec[0].back().first,y=vec[0].back().second;
				vec[0].pop_back();
				v=1;
			}
		}
		else{
			if(vec[1].empty()){
				x=vec[0].back().first,y=vec[0].back().second;
				vec[0].pop_back();
				v=2;
				if(ans[x-1][y]==2||ans[x+1][y]==2||ans[x][y-1]==2||ans[x][y+1]==2)
					v=3;
			}
			else{
				x=vec[1].back().first,y=vec[1].back().second;
				vec[1].pop_back();
				v=2;
			}
		}
		printf("%d %d %d\n",v,x,y);
		ans[x][y]=v;
		fflush(stdout);
	}
}