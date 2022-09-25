#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,m,k,p,ans=0;
string s;

pair <int,int> a[100000];

bool cmp(const int &a, const int &b){
	return a<b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a,a+n);
	int mn=a[0].first, mx=a[0].second;
	for (int i=1; i<n; i++) {
		if (mn<a[i].first && mx>a[i].second) ans++;
		mn=min(a[i].first,mn);
		mx=max(a[i].second,mx);
	}
	cout << ans;
	return 0;
}