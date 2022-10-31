#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

string s,l,t;

int main() {
	cin>>s>>l;
	for (int i=0; i<s.length(); i++)
		if (s[i]=='1' && l[i]=='1') t+='0'; else 
		if (s[i]=='1' && l[i]=='0') t+='1'; else 
		if (s[i]=='0' && l[i]=='1') t+='1'; else 
		t+='0';
	cout<<t;
     
     
     return 0;
}