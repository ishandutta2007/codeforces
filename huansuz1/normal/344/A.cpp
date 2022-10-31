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

int n,k,z=1;
string s;

int main() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>k;
		if (k==10){ 
			s+='-';
			s+='+'; 
		}	else   {
			s+='+';
		     s+='-';
		}
	}     
     for (int i=0; i<s.length()-1; i++)
	     if (s[i]==s[i+1]) z++;

	cout<<z;
     return 0;
}