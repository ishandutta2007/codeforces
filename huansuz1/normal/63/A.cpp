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
string s[12345],l[12345];
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++) 
		cin>>s[i]>>l[i] ;
	
	for(int i=1; i<=n; i++) {
		if (l[i]=="rat") cout<<s[i]<<endl;
	}

	for(int i=1; i<=n; i++) {
		if (l[i]=="child" || l[i]=="woman") cout<<s[i]<<endl;
	}
	for(int i=1; i<=n; i++) {
		if (l[i]=="man") cout<<s[i]<<endl;
	}
	for(int i=1; i<=n; i++) {
		if (l[i]=="captain") cout<<s[i]<<endl;
	}



	return 0;
}