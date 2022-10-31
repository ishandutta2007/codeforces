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

int n,a[223456],b[223456],m,x,y;
long long s1,s2;
string s="first";

int main() {
    cin>>n;
 	for(int i=0; i<n; i++){
 		cin>>m;
 		if (m>0) {a[x++]=m; s1+=m;} 
 			else {b[y++]=abs(m); s2+=abs(m);}
 	    if (i==n-1 && m<0) s="second";
	}
	if (s1>s2) {cout<<"first";exit(0);} 
		else if (s1<s2) {cout<<"second";exit(0);}
	int ma=x;
	if (ma<y) ma=y;
	for (int i=0; i<ma; i++)
		if (a[i]>b[i])  {cout<<"first";exit(0);}
			else if (a[i]<b[i]) {cout<<"second";exit(0);}
	cout<<s;
	return 0;
}