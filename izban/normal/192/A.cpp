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

const int maxn=1<<17, inf=1000000000;
const ll q=1000000007;
const double eps=1e-9;


int n,m;
vector<int> v;
map<int,bool> mp;

int f(int x) {
	return x*(x+1)/2;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	int x=1;
	while (f(x)<=n) {
		v.push_back(f(x));
		mp[f(x)]=true;
		x++;
	}
	for (int i=0; i<v.size(); i++) {
		if (mp[n-v[i]]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}