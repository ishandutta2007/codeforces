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

int n,m,x,y,b[123456],z;
string s;

int main() {
  	
  	cin>>s>>m;
  	
  	for (int i=0; i<s.length(); i++) {
  		if (s[i]==s[i+1])  z++; b[i+1]=z; }
  		
  	
  	for (int i=0; i<m; i++) {
  		cin>>x>>y;
  		cout<<b[y-1]-b[x-1]<<endl;
    }
    return 0;
}