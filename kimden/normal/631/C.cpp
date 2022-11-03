#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

bool operator< (pair<int,int> &x,pair<int,int> &y){
	return x.first<y.first;
}

int main()
{
	int n,m,k,a,b,c;
	deque<int> num;
	deque<int>ans;
	vector<pair<int,int>> query;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		num.push_back(a);
	}
	for(int i=0;i<m;i++){
		scanf("%D%D",&a,&b);
		vector<pair<int,int>>::iterator it=query.begin(),it2=query.end(),mid;
		if(!query.empty() && *it<make_pair(b,a)){
			query.clear();
		}else{
			while(it2-it>1){
				mid = it+(it2-it)/2;
				if(make_pair(b,a)<*mid){
					it = mid;
				}else{
					it2 = mid;
				}
			}
			query.erase(it2,query.end());
		}
		query.push_back(make_pair(b,a));
	}
	for(vector<pair<int,int>>::iterator i=query.begin();i!=query.end();){
		if(i!=query.begin() && (i-1)->second==i->second){
			query.erase(i);
		}else{
			i++;
		}
	}
	deque<int>::iterator nbeg=num.begin(),nend=num.end();
	for(vector<pair<int,int>>::iterator i=query.begin();i!=query.end();i++){
		if(i!=query.begin()){
			while(num.end()-num.begin()>i->first){
				if((i-1)->second==1){
					ans.push_front(num.back());
					num.pop_back();
				}else{
					ans.push_front(num.front());
					num.pop_front();
				}
			}
		}else{
			while(num.end()-num.begin()>i->first){
				ans.push_front(num.back());
				num.pop_back();
			}
			sort(num.begin(),num.end());
		}
	}
	while(!num.empty()){
		if((query.end()-1)->second==1){
			ans.push_front(num.back());
			num.pop_back();
		}else{
			ans.push_front(num.front());
			num.pop_front();
		}
	}
	for(auto i: ans){
		printf("%d ",i);
	}
	return 0;
}