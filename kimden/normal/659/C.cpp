#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,m,a,cost=0,count=0,maks=0,p;
	vector<int> v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	auto it = v.begin();
	p=1;
	while(p+cost<=m){
		if(it!=v.end() && *it==p){
			it++;
		}else{
			cost+=p;
			count++;
			maks=p;
		}
		p++;
	}
	cout << count << "\n";
	it = v.begin();
	p=1;
	bool b=false;
	while(p<=maks){
		if(it!=v.end() && *it==p){
			it++;
		}else{
			if(b){
				cout << " ";
			}
			cout << p;
			b=true;
		}
		p++;
	}
	return 0;
}