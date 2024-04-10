//mukh1t dauirkhan
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include<string>


using namespace std;


int n,a[12],m,b[10];
	string s;

int main() {

		
	cin>>s;
	for (int i=0; i<s.length(); i++)
		a[m++]=(s[i]-'0');	
	

	b[0]=2;
	b[1]=7;                        
	b[2]=2;
	b[3]=3;
	b[4]=3;
	b[5]=4;
	b[6]=2;
	b[7]=5;
	b[8]=1;
	b[9]=2;
	int ss=1;
	for (int i=0; i<m; i++)
		ss*=b[a[i]];
	cout<<ss;
	return 0;
}