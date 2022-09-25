#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:64000000")

const int maxn=1<<17, inf=1000000007;
const double eps=1e-9;

string a,b;

int main() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	cin >> a >> b;
	if (a.length()!=b.length()) { cout << "NO"; return 0; }
	vector<pair<char,char>> v;
	for (int i=0; i<a.length(); i++) if (a[i]!=b[i]) v.push_back(make_pair(a[i],b[i]));
	if (v.size()!=2) cout << "NO";
	else if (v[0].first==v[1].second && v[0].second==v[1].first) cout << "YES";
	else cout << "NO";

    return 0;
}