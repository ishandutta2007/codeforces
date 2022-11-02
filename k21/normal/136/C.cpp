#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define DEBUG(x) cout << '>' << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

using namespace std;

int n;
int data[100057];

int main() {
	scanf("%d", &n);
	REP(i,n) scanf("%d",data+i);
	sort(data, data+n);
	if (data[n-1] == 1) {
		data[n-1] = 2;
	} else {
		FORD(i,n-1,1)data[i] = data[i-1];
		data[0] = 1;
	}
	REP(i,n) printf((i==n-1)?"%d\n":"%d ", data[i]);
	return 0;
}