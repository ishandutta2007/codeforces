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

const int maxn=210;

int n,m,k[maxn],pusto;
vector<int> v[maxn];
pair<int,int> a[maxn];
vector<pair<int,int>> ans;


void doit(int cur, int i, int j) {
	if (a[cur]==make_pair(-1,-1)) {
		pusto=v[i][j];
		a[cur]=make_pair(i,j);
		a[v[i][j]]=make_pair(-1,-1);
		ans.push_back(make_pair(v[i][j],cur));
	} else {
		v[a[cur].first][a[cur].second]=pusto;
		a[pusto]=make_pair(a[cur].first,a[cur].second);
		ans.push_back(make_pair(cur,pusto));
		ans.push_back(make_pair(v[i][j],cur));
		a[v[i][j]]=make_pair(-1,-1);
		pusto=v[i][j];
		a[cur]=make_pair(i,j);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i=0; i<maxn; i++)
		a[i]=make_pair(-1,-1);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> k[i];
		for (int j=0; j<k[i]; j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
			a[x]=make_pair(i,j);
		}
	}
	for (int i=1; i<=n; i++) 
		if (a[i]==make_pair(-1,-1)) 
			pusto=i;
	int cur=1;
	for (int i=0; i<m; i++) {
		for (int j=0; j<k[i]; j++) {
			if (v[i][j]!=cur) {
				/*if (a[cur]!=make_pair(-1,-1)) {
					v[a[cur].first][a[cur].second]=v[i][j];
					ans.push_back(make_pair(cur,v[i][j]));
					a[v[i][j]]=a[cur];
					a[cur]=make_pair(i,j);
				}*/
				doit(cur,i,j);
			}
			cur++;
		}
	}

	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}