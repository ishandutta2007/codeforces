#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define point pair<int,int>
#define x first
#define y second

bool isLeft(point q,point w,point e){
	point o,p;
	o.x = w.x-q.x;
	o.y = w.y-q.y;	
	p.x = e.x-w.x;
	p.y = e.y-w.y;
	if(o.x*p.y>o.y*p.x){
		return true;
	}
	return false;
}

int main(){
	int n,a,b,ans=0;
	vector<point> v;
	scanf("%d",&n);
	for(int i=0;i<n+1;i++){
		scanf("%d%d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	for(auto it = v.begin()+1;it!=v.end()-1;it++){
		if(isLeft(*(it-1),*it,*(it+1))){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}