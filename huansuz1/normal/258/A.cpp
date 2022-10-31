#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n , a[4] , z , d, p=-1;
string s;


int main(){
	cin >> s;

	for (int i=0; i< s.length(); i++)
		if (s[i] == '0') {p=i; break;}

		if (p==-1) {
		for (int i=1; i<s.length(); i++)
			cout<<s[i];
		}else {
		for (int i=0; i<p; i++)
			cout<<s[i];
		for (int i=p+1; i<s.length(); i++)
			cout<<s[i];
		
		}
		
	
	return 0;
}