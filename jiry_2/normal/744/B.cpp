#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n;
int ans[1100],w[1100];
vector<int>way;
void getask(){
	printf("%d\n",way.size()); fflush(stdout);
	for (int i=0;i<way.size();i++) printf("%d ",way[i]);
	printf("\n"); fflush(stdout);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
}
int main(){
	memset(ans,0x3f,sizeof ans);
	scanf("%d",&n);
	for (int now=0;(1<<now)<=n;now++){
		way.clear();
		for (int i=1;i<=n;i++)
			if (i&(1<<now)) way.push_back(i);
		getask();
		for (int i=1;i<=n;i++)
			if ((i&(1<<now))==0) ans[i]=min(ans[i],w[i]);
		way.clear();
		for (int i=1;i<=n;i++)
			if ((i&(1<<now))==0) way.push_back(i);
		getask();
		for (int i=1;i<=n;i++)
			if ((i&(1<<now))) ans[i]=min(ans[i],w[i]);
	}
	printf("-1\n"); fflush(stdout);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n"); fflush(stdout);
	return 0;
}