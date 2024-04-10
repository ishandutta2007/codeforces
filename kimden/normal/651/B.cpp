#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n,a;
	scanf("%d",&n);
	map<int,int> m;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		m[a]++;
	}
	int ans=-1;
	while(!m.empty()){
		ans++;
		map<int,int>::iterator j;
		for(map<int,int>::iterator i=m.begin();i!=m.end();){
			//printf("%d ",i->first);
			i->second--;
			if(i->second==0){
				j=i;
				i++;
				m.erase(j->first);
			}else{
				i++;
			}
		}
	}
	ans = n-1-ans;
	printf("%d",ans);
	return 0;
}