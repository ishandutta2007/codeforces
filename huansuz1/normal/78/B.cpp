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

int n,z;

int main() {
	cin>>n;            
	string s="ROYGBIV";
	string s1="GBIVGBIV";
	for (int i=0;i<n/7;i++)
		cout<<s;
	for (int i=0;i<n%7;i++)
		cout<<s1[i];

	return 0;
}