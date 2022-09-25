#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
long long a[20000],l,r,ans;


void dfs(long long x) {
	if (x>1e10) return;
	a[++a[0]]=x;
	dfs(10*x+4); dfs(10*x+7);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);       
	freopen("output.txt", "w", stdout);
#endif
	dfs(4); dfs(7);
	a[++a[0]]=4444444444LL;
	sort(a+1,a+a[0]+1);
	cin >> l >> r; int i=0;
	while (true) {
		i++;
		if (l>r) break;
		if (a[i]<l) continue;
		ans+=a[i]*(min(a[i]-l+1,r-l+1));
		l=a[i]+1;
	}
	cout << ans;
	return 0;
}