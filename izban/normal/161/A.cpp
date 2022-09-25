#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=100100;

int n,m,x,y,a[maxn],b[maxn],ans;
string s;
vector<pair<int,int> > v;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m >> x >> y;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int j=0; j<m; j++) cin >> b[j];

	int i=0,j=0;
	while (i<n && j<m) {
		if (b[j]>=a[i]-x && b[j]<=a[i]+y) {
			ans++;
			v.push_back(make_pair(i+1,j+1));
			i++; j++;
		} else
		if (b[j]<a[i]-x) j++;
		else if (b[j]>a[i]+y) i++;
	}
	cout << ans << endl;
	for (int i=0; i<v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
	return 0;
}