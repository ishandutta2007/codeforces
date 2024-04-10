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

const int maxn=2*100100;

int n,m,k,ans;
int a[maxn];
vector<pair<int,int>> e[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m >> k;
	int l=-1;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (l==-1 || a[i]!=a[l]) {
			if (l!=-1) e[a[l]].push_back(make_pair(l,i-1));
			l=i;
		}
	}
			e[a[n-1]].push_back(make_pair(l,n-1));
			l=n;


	for (int i=0; i<maxn; i++) {
		int j1=-1;
		int cursum=0, curk=k;
		for (int j=0; j<e[i].size(); j++) {
			if (j1<j) cursum+=e[i][j].second-e[i][j].first+1;
			j1=max(j1,j);
			while (j1<(int)e[i].size()-1 && e[i][j1+1].first-e[i][j1].second-1<=curk) {
				curk-=e[i][j1+1].first-e[i][j1].second-1;
				j1++;
				cursum+=e[i][j1].second-e[i][j1].first+1;
			}
			ans=max(ans,cursum);
			if (j<(int)e[i].size()-1 && j1>j) curk+=e[i][j+1].first-e[i][j].second-1;
			cursum-=e[i][j].second-e[i][j].first+1;
		}
	}
	cout << ans;
	return 0;
}