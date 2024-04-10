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

int n,d,a,b;
//pair<int,int> c[maxn];

struct client {
	int x,y,p;
	bool operator< (const client &c) {
		return x*a+y*b<c.x*a+c.y*b || x*a+y*b==c.x*a+c.y*b && p<c.p;
	}
} c[maxn];

bool cmp(const pair<int,int> &x, const pair<int,int> &y) {
	return x.first*a+x.second*b<y.first*a+y.second*b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> d >> a >> b;
	for (int i=0; i<n; i++) {
		cin >> c[i].x >> c[i].y;
		c[i].p=i+1;
	}
	sort(c,c+n);
	for (int i=0; i<n; i++) {
		if (d-c[i].x*a-c[i].y*b>=0){ 
			d-=c[i].x*a+c[i].y*b;
		} else {
			cout << i << endl;
			vector<int> ans;
			for (int j=0; j<i; j++) {
				ans.push_back(c[j].p);
			}
			sort(ans.begin(),ans.end());
			for (int j=0; j<ans.size(); j++) 
				cout << ans[j] << ' ';
			return 0;
		}
	}
	cout << n << endl;
	for(int i=0; i<n; i++) cout << i+1 << ' ';
	return 0;
}