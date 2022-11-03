#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct point{
	int x,y;
	point(int a=0,int b=0): x(a),y(b){}
	void operator()(int a=0,int b=0){x=a;y=b;}
	void norm(){
		if(x<0){
			this->operator()(-x,-y);
		}else if(x==0 && y<0){
			this->operator()(0,-y);
		}
	}
	bool operator==(point&t){
		return (x==t.x)&&(y==t.y);
	}
	bool operator!=(point&t){
		return (x!=t.x)||(y!=t.y);
	}
	bool operator<(point&t){
		return (x<t.x)||((x==t.x)&&(y<t.y));
	}
	point operator-(point&t){
		return point(x-t.x,y-t.y);
	}
};
int main()
{
	vector<point> pts;
	vector<point> vect;
	vector<pair<point,int>> mp;
	long long ans=0;
	point cur,cur2;
	int n,x,y;
	cin >> n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		cur(x,y);
		for(int j=0;j<pts.size();j++){
			cur2 = cur-pts[j];
			cur2.norm();
			vect.push_back(cur2);
		}
		pts.push_back(cur);
	}
	sort(vect.begin(),vect.end());
	auto it = vect.begin();
	int count=0;
	for(auto i:vect){
		i.norm();
	}
	while(it!=vect.end()){
		if((it==vect.begin() ||(*(it-1))==(*(it)))){
			count++;
		}else if(count>=2){
			mp.push_back(make_pair((*(it-1)),count));
			count = 1;
		}else{
			count = 1;
		}
	/*	if((it==vect.begin() ||(*(it-1))!=(*(it))) && (it+1==vect.end() || (*(it+1))!=(*(it)))){
			//it = vect.erase(it);
			count = 0;
		}else{
			it++;
		}*/
		it++;
	}
	if(count>=2){
		mp.push_back(make_pair((*(it-1)),count));
	}
	for(auto i:mp){
		ans += (i.second*(i.second-1));
		//cout << i.first.x << " " <<i.first.y <<" " <<i.second << "\n";
	}
	ans/=4;
	cout << ans;	
	return 0;
}