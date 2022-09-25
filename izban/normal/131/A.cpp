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


int n,a[200],ans=0,sum=0;
string s;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	bool f=true;
	for (int i=0; i<s.length(); i++) {
		if (i>0 && s[i]>='a' && s[i]<='z') f=false;
	}
	if (f) {
		for (int i=0; i<s.length(); i++) {
			if (s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
			else s[i]=s[i]-'a'+'A';
		}
	}
	cout << s;
	return 0;
}