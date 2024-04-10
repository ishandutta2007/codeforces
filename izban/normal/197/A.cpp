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

const int maxn=100100, mod=1000000007;
const double eps=1e-9;
const ll q=239;



int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a,b,r;
	cin >> a >> b >> r;
	cout << (2*r<=min(a,b)?"First":"Second");

	return 0;
}