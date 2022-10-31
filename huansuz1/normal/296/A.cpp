#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;


map<int,int> mp;
int n,p,ma;

int main(){
	cin>>n;
	for (int i=0; i<n; i++)  {
		cin>>p;
		mp[p]++;
		if (mp[p]>ma) ma=mp[p];
	}
	if (ma<=(n+1)/2 || n==1) cout<<"YES"; else cout<<"NO";


	return 0;
}