#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	int n;
	long long ans = 0;
	cin >> n;
	int last; long long cnt=0;
	for (int i=0;i<n;i++) {
		int x; scanf("%d",&x);
		if (i == 0 || last != x) {
			ans += (cnt+1)*cnt/2;
			last = x;
			cnt = 1;
		} else cnt++;
	}
	ans += (cnt+1)*cnt/2;
	cout << ans;
	
	return 0;
}