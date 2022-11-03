#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,s,d,k,t1,t2;
	vector<int> w;
	vector<pair<int,int>> stones;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		w.push_back(k);
	}
	sort(w.begin(),w.end());
	int l=0,r=0,i=0;
	while(i!=n){
		l = w[i]-1;
		r = w[i]+1;
		while(i<n-1 && w.at(i+1)-w.at(i)<s+2){
			i++;
		}
		r = w[i]+1;
		if(r-l>d || l==0 || l<s){
			printf("IMPOSSIBLE");
			return 0;
		}
		stones.emplace_back(l+1,r-1);
		i++;
	}
	int x,y;
	x=-1;
	y=0;
	for(auto j: stones){
		x=j.first-1;
		printf("RUN %d\n",x-y);
		y=j.second+1;
		printf("JUMP %d\n",y-x);
	}
	x=m;
	if(x>y)
		printf("RUN %d\n",x-y);
	return 0;
}