#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
string s,t="CODEFORCES";
int main() {

	cin>>s;
	int n=s.length(),k=9,z=0;
	for (int i=0; i<n; i++)
		if (s[i]==t[i]) z++; else break;
    for (int i=n-1; i>=0; i--)
    	if (s[i]==t[k--]) z++; else break;
	if (z>=10)cout<<"YES"; else cout<<"NO";
	}