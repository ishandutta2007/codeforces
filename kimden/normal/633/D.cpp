#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using std::vector;
#define big 2000000000

int main()
{
	vector<int> v,v1;
	vector<int>::iterator it;
	bool found;
	v.clear();
	int n;
	int u0,u1,u2;
	int a,count,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		v.push_back(a);
	}
	std::sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==i || (j>0 && (v.at(j-1)==v.at(j)))){
				continue;
			}
			found=true;
			v1 = v;
			u0=v1.at(i);
			u1=v1.at(j);
			it = v1.begin();
			for(int w=0;w<i;w++){
				it++;
			}
			v1.erase(it);
			it = v1.begin();
			for(int w=0;w<(i<j? j-1:j);w++){
				it++;
			}
			v1.erase(it);
			it = v1.begin();
			count = 2;
			while(found){
				u2 = u0+u1;
				if(u2>big || u2<-big){
					found=false;
				}else{
					it = std::find(v1.begin(),v1.end(),u2);
					found = (it!=v1.end());
					if(found){
						v1.erase(it);
						count++;
					}else break;
				}
				u0=u1;
				u1=u2;
			}
			if(count>ans)
				ans=count;
		}
	}
	printf("%d",ans);
	return 0;
}