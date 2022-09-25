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

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n >> m;

	if (n==0 && m==0) 
		cout << "0 0";
	else if (!n) 
		cout << "Impossible";
	else
		cout << n+m-min(n,m) << ' ' << n+m-(m>0);

	return 0;
}