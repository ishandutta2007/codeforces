#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;

int n;
pair<int,int> a[maxn];
map<int,pair<int,int> > mp;
map<int,int> col;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
		mp[a[i].first].first++;
		mp[a[i].second].second++;
		if (a[i].first==a[i].second) col[a[i].first]++;
	}
	int ans=maxn;
	for (map<int,pair<int,int> > :: iterator it=mp.begin(); it!=mp.end(); it++) {
		if ((it->second.second+it->second.first-col[it->first])*2>=n) {
			if (it->second.first*2>=n) ans=0;
			else ans=min(ans,(n+1)/2-it->second.first);
		}
	}
	if (ans==maxn) ans=-1;
	cout << ans;
	return 0;
}