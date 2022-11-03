#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	map<int,pair<int,int>> m;
	int n,a,i,b=0,c,ans=-1;
	scanf("%d",&n);
	c = n;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		m[a] = make_pair(m[a].first+1,i);
	}
	for(auto k: m){
		if(ans==-1 || (k.second.first>b || (k.second.first==b && k.second.second<c))){
			ans = k.first;
			b = k.second.first;
			c = k.second.second;
		}
	}
	printf("%d",ans);
	return 0;
}