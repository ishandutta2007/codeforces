#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int n,m;
pair<int,int> a[123456];

int main(){
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i].first>>a[i].second;
	sort(a,a+n);
	int ma=0;
	for (int i=0; i<n; i++){
		if (a[i].second>=ma) ma=a[i].second; else ma=a[i].first;
		
	
	}
	cout<<ma;
	
	
		

return 0;
}