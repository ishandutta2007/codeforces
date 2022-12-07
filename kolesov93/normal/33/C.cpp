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
#define N 111111
int n;
long long a[N],f[N];


int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	scanf("%d",&n);
	long long s = 0;
	for (int i=1;i<=n;i++) { 
		int x;
		scanf("%d",&x); a[i] = x;
		s += a[i];
		f[i] = a[i] + f[i-1];
	}
	
	long long ans = max(s,-s);
	long long cool = 0;
	for (int i=1;i<=n;i++) {
			ans = max(ans,-s+2*(f[i]-cool));
			cool = min(cool,f[i]);		
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}