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

int n,m,k,p,ans=0;
string s;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> s; s+='o';
	int l=0; char c=s[0];
	for (int i=1; i<s.length(); i++) {
		if (s[i]!=c || i-l+1>5) {
			ans+=1;
			l=i;
			c=s[i];
		}
	}
	cout << ans;


	return 0;
}