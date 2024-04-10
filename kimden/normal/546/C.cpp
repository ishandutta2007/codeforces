#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n,k1,k2,a,p1,p2;
	deque<int> v1,v2,vb1,vb2;
	deque<int> res;
	vector<pair<deque<int>,deque<int>>> history;
	cin >> n;
	cin >> k1;
	for(int i=0;i<k1;i++){
		cin >> a;
		v1.push_back(a);
	}
	cin >> k2;
	for(int i=0;i<k2;i++){
		cin >> a;
		v2.push_back(a);
	}
	vb1 = v1;
	vb2 = v2;
	history.push_back(make_pair(v1,v2));
	while((v1.size()!=0 && v2.size()!=0)){
		p1 = v1.front();
		p2 = v2.front();
		v1.pop_front();
		v2.pop_front();
		if(p1>p2){
			v1.push_back(p2);
			v1.push_back(p1);
			res.push_back(1);
		}else{
			v2.push_back(p1);
			v2.push_back(p2);
			res.push_back(2);
		}
		for(auto h: history){
			if(h.first==v1 && h.second==v2){
				cout << -1;
				return 0;
			}
		}
		history.push_back(make_pair(v1,v2));
	}
	cout << res.size() << " " << res.back();
	return 0;
}