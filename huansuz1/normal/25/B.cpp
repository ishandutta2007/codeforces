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

int n;
string s,l[123];

int main(){
	cin>>n>>s;
	if (n<4)  {cout<<s; return 0;}
	
	int k=0,z=0;
	for (int i=0; i<s.length(); i++){
		z++;
		if (z==3) {z=1; k++;}
		l[k]+=s[i]; 	
	}
	if (l[k].length()==1){ l[k-1]+=l[k]; k--;}
	cout<<l[0];
	for (int i=1; i<=k; i++)
		cout<<'-'<<l[i];

	return 0;
}