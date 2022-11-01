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
map<string,string> ar;
string s[12345],x,y,l[12345],r[12345];
int n,m,p;

int main(){
	cin>>n>>m;
	for (int i=0; i<m; i++) {
		cin>>l[i]>>r[i];
		x=l[i];
		y=r[i];
		if (x.length()>y.length()) ar[x]=y; else ar[x]=x;	
	}


	for (int i=0; i<n; i++){
		cin>>s[i];
		cout<<ar[s[i]]<<' ';
		}
	
	return 0;
}