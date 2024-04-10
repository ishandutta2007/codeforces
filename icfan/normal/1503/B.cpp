#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
const int Maxn=100;
int n;
std::queue<std::pair<int,int> > lis[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			lis[(i+j)&1].push(std::make_pair(i,j));
		}
	}
	for(int i=1;i<=n*n;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			if(lis[1].empty()){
				int x=lis[0].front().first,y=lis[0].front().second;
				lis[0].pop();
				printf("3 %d %d\n",x,y);
			}
			else{
				int x=lis[1].front().first,y=lis[1].front().second;
				lis[1].pop();
				printf("2 %d %d\n",x,y);
			}
		}
		else if(t==2){
			if(lis[0].empty()){
				int x=lis[1].front().first,y=lis[1].front().second;
				lis[1].pop();
				printf("3 %d %d\n",x,y);
			}
			else{
				int x=lis[0].front().first,y=lis[0].front().second;
				lis[0].pop();
				printf("1 %d %d\n",x,y);
			}
		}
		else{
			if(lis[0].empty()){
				int x=lis[1].front().first,y=lis[1].front().second;
				lis[1].pop();
				printf("2 %d %d\n",x,y);
			}
			else{
				int x=lis[0].front().first,y=lis[0].front().second;
				lis[0].pop();
				printf("1 %d %d\n",x,y);
			}
		}
		fflush(stdout);
	}
	return 0;
}