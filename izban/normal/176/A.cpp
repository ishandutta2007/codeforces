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

const int maxn=110;
const double eps=1e-9;


int n,m,k1,ans;
string s[maxn];
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int d[maxn];



bool cmp(pair<int,int> a, pair<int,int> b) {
	return (double)a.first/a.second - (double)b.first/b.second < eps;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m >> k1;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		for (int j=0; j<m; j++) {
			cin >> a[i][j] >> b[i][j] >> c[i][j];
			d[j]=max(d[j],b[i][j]);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) if (i!=j) {
			int cans=0,curk=k1;
			vector<pair<int,int>> v;
			for (int k=0; k<m; k++) 
				if (b[j][k]-a[i][k]>0) v.push_back(make_pair(b[j][k]-a[i][k],c[i][k]));
			sort(v.begin(),v.end());
			for (int i=v.size()-1; i>=0; i--) {
				if (v[i].first>0) cans+=v[i].first*min(curk,v[i].second);
				curk-=min(curk,v[i].second);
				if (curk==0) break;
			}
			if (cans>ans) ans=cans;
		}
	}
	/*for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j]<d[j]) 
				ans+=(d[j]-a[i][j])*c[i][j];
		}
	}*/
	cout << ans;
	return 0;
}