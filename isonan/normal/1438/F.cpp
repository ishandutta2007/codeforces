#include <cstdio>
#include <random>
#include <algorithm>
#include <vector>
#include <ctime>

int h;
std::mt19937 rnd(time(0));
int Get(){
	for(;;){
		int x=rnd()&((1<<h)-1);
		if(x)return x;
	}
}
int cnt[1048576];
int query(int a,int b,int c){
	printf("? %d %d %d\n",a,b,c);
	fflush(stdout);
	scanf("%d",&a);
	return a;
}
int main(){
	scanf("%d",&h);
	for(int i=1;i<=422;++i){
		int u=Get(),v=Get(),w=Get();
		while(u==v)v=Get();
		while(u==w||v==w)w=Get();
		++cnt[query(u,v,w)];
	}
	std::vector<std::pair<int,int> >vec;
	for(int i=1;i<1<<h;++i)vec.push_back(std::make_pair(cnt[i],i));
	std::sort(vec.begin(),vec.end());
	int u=vec.back().second;vec.pop_back();
	int v=vec.back().second;vec.pop_back();
	for(int i=1;i<(1<<h);++i)
		if(i!=u&&i!=v){
			if(query(i,u,v)==i){
				printf("! %d\n",i);
				fflush(stdout);
				return 0;
			}
		}
}