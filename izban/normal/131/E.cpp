#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

#define sqr(x) ((x)*(x))

int n,m,k,x[100000],y[100000];
int t[9];
//vector<int> hor[100000],ver[100000],d1[200000],d2[300000];
map <int,vector<int>> hor,ver,d1,d2;

int bin(vector <int> &a, int b) {
	int l=0, r=a.size()-1;
	while (r-l>1) {
		int m=(r+l)/2;
		if (a[m]>b) r=m;
		else l=m;
	}
	if (a[l]==b) return l; 
	if (a[r]==b) return r;
}

int main() {

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);       
        freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> x[i] >> y[i];
		hor[y[i]].push_back(x[i]);
		ver[x[i]].push_back(y[i]);
		d1[x[i]+y[i]].push_back(x[i]-y[i]);
		d2[x[i]-y[i]].push_back(x[i]+y[i]);
	}
	for (int i=1; i<=n; i++) {
		sort(hor[i].begin(),hor[i].end());
		sort(ver[i].begin(),ver[i].end());
	}
	for (int i=1; i<=2*n; i++) sort(d1[i].begin(),d1[i].end());
	for (int i=-n; i<=n; i++) sort(d2[i].begin(),d2[i].end());

	for (int i=0; i<m; i++) {
		int k=0,o=0;

		o=bin(hor[y[i]],x[i]);
		k+=(o>0) + (o<hor[y[i]].size()-1);

		o=bin(ver[x[i]],y[i]);
		k+=(o>0) + (o<ver[x[i]].size()-1);

		o=bin(d1[x[i]+y[i]],x[i]-y[i]);
		k+=(o>0) + (o<d1[x[i]+y[i]].size()-1);

		o=bin(d2[x[i]-y[i]],x[i]+y[i]);
		k+=(o>0) + (o<d2[x[i]-y[i]].size()-1);

		t[k]++;
	}
	for (int i=0; i<9; i++) cout << t[i]  << ' ';
	return 0;
}