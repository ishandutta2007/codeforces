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

int n,m,a[27],ma;
map<string,int> mp;
string s,l;

int main(){
      	cin>>n;
      	for (int i=0; i<n; i++){
      		cin>>s;
      		mp[s]++;
      		if (mp[s]>ma) {ma=mp[s]; l=s;}
      	}
      		cout<<l;
      return 0;
}