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

int n,m,k,p,ans;
string s;

string a,b,c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> a >> b >> c;
	a+=b;
	sort(a.begin(),a.end());
	sort(c.begin(),c.end());
	if (a==c) cout << "YES";
	else cout << "NO";
	return 0;
}