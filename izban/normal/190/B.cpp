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

	int x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	cout.precision(20);
	cout << fixed;
	double d=sqrt(sqr(x2-x1)+sqr(y2-y1)+.0);
	if (d>r1+r2+eps)
		cout << (d-r1-r2)/2.0;
	else if (d+min(r1,r2)<max(r1,r2))
		cout << (max(r1,r2)-d-min(r1,r2))/2.0;
	else
		cout << 0;

	return 0;
}