#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef vector<int>V;
int n,a[N],m,x,i,Z;
unordered_map<int,int>mp[N];
V b[N],bb[N];
int dfs(int l,int r){
	if(mp[r].count(l))return mp[r][l];
	int&ans=mp[r][l]=0;
	for(int y:b[r])if(r-y*2+1>=l)ans=max(ans,dfs(l,r-y)+1);
	for(int y:bb[l])if(l+y*2-1<=r)ans=max(ans,dfs(l+y,r)+1);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(;n--;){
		scanf("%d",&x);a[m+1]=x;
		if(a[m]==x)b[m+1]={1};for(int y:b[m])if(a[m-y*2]==x)b[m+1].push_back(y+1);
		++m;i=0;for(int y:b[m])if(binary_search(b[m-y].begin(),b[m-y].end(),y))i=y;
		for(int y:b[m])bb[m-y*2+1].push_back(y);
		if(i)for(i*=2,++Z;i--;){
			for(int y:b[m])bb[m-y*2+1].pop_back();
			b[m].clear(),mp[m].clear(),--m;
		}else dfs(1,m);
		printf("%d ",Z*2+mp[m][1]);
	}
	puts("");
}