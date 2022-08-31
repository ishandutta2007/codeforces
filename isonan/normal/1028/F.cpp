#include <cstdio>
#include <vector>
#include <map>

std::map<std::pair<int,int>,int>ans;
std::map<long long,int>map2;
std::vector<std::pair<int,int> >vec[200001];
int q,cnt;
int gcd(int a,int b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%d",&q);
	int Cnt=0;
	for(int i=1,t,x,y;i<=q;i++){
		scanf("%d%d%d",&t,&x,&y);
		int g=gcd(x,y);
		if(t==1){
			++Cnt;
			int &p=map2[1ll*x*x+1ll*y*y];
			if(!p)p=++cnt;
			vec[p].push_back(std::make_pair(x,y));
			for(int j=0;j<vec[p].size();j++){
				int X=x+vec[p][j].first,Y=y+vec[p][j].second,G=gcd(X,Y);
//				printf("%d %d\n",X/G,Y/G);
				ans[std::make_pair(X/G,Y/G)]+=2-(vec[p][j].first==x&&vec[p][j].second==y);
			}
		}
		else if(t==2){
			--Cnt;
			int &p=map2[1ll*x*x+1ll*y*y];
			for(int j=0;j<vec[p].size();j++){
				int X=x+vec[p][j].first,Y=y+vec[p][j].second,G=gcd(X,Y);
				ans[std::make_pair(X/G,Y/G)]-=2-(vec[p][j].first==x&&vec[p][j].second==y);
			}
			for(int j=0;j<vec[p].size();j++)
				if((vec[p][j].first==x&&vec[p][j].second==y))std::swap(vec[p][j],vec[p].back());
			vec[p].pop_back();
		}
		else{
//			printf("%d %d\n",Cnt,ans[std::make_pair(x/g,y/g)]);
			printf("%d\n",Cnt-ans[std::make_pair(x/g,y/g)]);
		}
	}
}