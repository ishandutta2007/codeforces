#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <set>
#include <sstream>
#include <queue>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

const int maxn=100100;

int n,sum,ans;
pair <int,int>  a[maxn];

bool cmp(pair <int,int> &a, pair<int,int> &b) {
	return a.second>b.second || a.second==b.second && a.first>b.first;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a,a+n,cmp);
	int x=1;
	for (int i=0; i<n && x; i++) {
		x--;
		x+=a[i].second;
		ans+=a[i].first;
	}
	cout << ans;
	return 0;
}