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

set<char> st;
set<char> :: iterator it;

int n, x, m;
char ch;

int main() {
    while( 	cin>>ch ) {
     	st.insert(ch);  }
    
	
	for(it=st.begin(); it!=st.end(); it++)
		if (*it>='a' && *it<='z') n++;
	cout<<n;
	return 0;
}