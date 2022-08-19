#include <cstdio>
#include <vector>
#include <cassert>

int n,a[1001];
std::vector<int>vec;
std::vector<std::pair<int,int> >ans;
void move(int x,int y){
	assert(a[x]<=a[y]);
	a[y]-=a[x];
	a[x]<<=1;
	ans.push_back(std::make_pair(x,y));
}
int del(int x,int y,int z){
	if(a[x]>a[y])std::swap(x,y);
	if(a[x]>a[z])std::swap(x,z);
	if(a[y]>a[z])std::swap(y,z);
	if(!a[x])return x;
	if(a[x]==a[y]){
		move(x,y);
		return y;
	}
	if(a[y]==a[z]){
		move(y,z);
		return z;
	}
	int v=a[x];
	for(int i=0;a[y]>=v;i++){
		if((a[y]/v)&(1<<i)){
			move(x,y);
		}
		else{
			move(x,z);
			if(a[z]==a[y]){
				move(y,z);
				return z;
			}
		}
	}
	return del(x,y,z);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i])vec.push_back(i);
	}
	if(vec.size()<2){
		puts("-1");
		return 0; 
	}
	while(vec.size()>2){
		int now=del(vec[0],vec[1],vec[2]);
		for(int i=0;i<3;i++)
			if(vec[i]==now){
				std::swap(vec.back(),vec[i]);
				vec.pop_back();
				break;
			}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
}