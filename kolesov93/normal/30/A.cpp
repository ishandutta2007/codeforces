#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <memory.h>
using namespace std;
long long a,b,c;

long long mabs(long long x) {
	if (x < 0) return -x;
	else return x;
}

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	int n;
	cin >> a >> b >> n;
	for (int i=-1000;i<=1000;i++) {
		long long aa = a;
		for (int j=0;j<n;j++) {
			aa *= i;
			if (mabs(aa) > mabs(b)) break;
		}
		if (aa == b) {
			cout << i;
			return 0;
		}
	}
	
	puts("No solution");
	
	return 0;
}