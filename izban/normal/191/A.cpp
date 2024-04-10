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

string str(int i) {
	stringstream ss;
	ss << i;
	string res="";
	ss >> res;
	return res;
}

const int maxn=1<<19, inf=1000000000;
const ll q=1000000007;
const double eps=1e-9;


int n,m,ans;
string a[maxn];
int d[26][26];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	a[n]="#";

	for (int i=0; i<26; i++) for (int j=0; j<26; j++) if (i!=j) d[i][j]=-inf;
	for (int i=0; i<n; i++) {
		char c1=a[i][0], c2=a[i][a[i].length()-1];
		for (int j=0; j<26; j++)
			d[j][c2-'a']=max(d[j][c2-'a'],d[j][c1-'a']+(int)a[i].length());
		ans=max(ans,d[c2-'a'][c2-'a']);
	}

	cout << ans;
	return 0;
}