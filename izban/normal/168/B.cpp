#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long


string s,ans;
bool k=false, g=false;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (getline(cin,s)) {
		bool f=false;
		for (int i=0; i<s.length(); i++) {
			if (s[i]=='#') f=true;
			if (s[i]!=' ') break;
		}
		if (f) {
			if (k && (g || ans.length())) cout << ans << endl;
			g=false;
			cout << s << endl;
			ans="";
			k=true;
			continue;
		}
		for (int i=0; i<s.length(); i++)
			if (s[i]!=' ')
				ans+=s[i];
		bool h=false;
		for (int i=0; i<s.length(); i++) 
			if (s[i]!=' ') h=true;
		if (!h) g=true;
		k=true;
	}
	if (ans!="" || g) cout << ans << endl;
	return 0;
}