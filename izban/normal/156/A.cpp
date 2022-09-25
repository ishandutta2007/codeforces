#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int o=100000;
string s,t;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s >> t;
	for (int i=0; i<=2000; i++) s='#'+s+'#';
		for (int i=0; i<s.length()-t.length()+1; i++) {
			int ans=0;
			for (int j=0; j<t.length(); j++) 
				ans+=s[i+j]!=t[j];
			o=min(ans,o);
		}
	/*else {
		for (int i=0; i<(int)t.length()-(int)s.length()+1; i++) {
			int ans=0;
			for (int j=0; j<s.length(); j++) 
				ans+=t[i+j]!=s[j];
			o=min(ans,o);
		}
		o+=(int)t.length()-(int)s.length();
	}*/

	cout << o;
	return 0;
}