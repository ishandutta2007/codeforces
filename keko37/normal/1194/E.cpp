#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int n;
int xx1[MAXN], yy1[MAXN], xx2[MAXN], yy2[MAXN];
vector <int> a, b;
bitset <MAXN> bt[MAXN];

bool sijeku (int i, int j) {
	if (xx1[i] != xx2[i]) swap(i, j);
	return yy1[i] <= yy1[j] && yy2[j] <= yy2[i] && xx1[j] <= xx1[i] && xx2[i] <= xx2[j];
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> xx1[i] >> yy1[i] >> xx2[i] >> yy2[i];
		if (xx1[i] > xx2[i]) swap(xx1[i], xx2[i]);
		if (yy1[i] > yy2[i]) swap(yy1[i], yy2[i]);
		if (xx1[i] == xx2[i]) a.push_back(i); else b.push_back(i);
	}
	if (a.size() > b.size()) swap(a, b);
	int siz = a.size();
	for (int i=0; i<siz; i++) {
		for (int j=0; j<b.size(); j++) {
			bt[i][j] = sijeku(a[i], b[j]);
		}
	}
	long long sol = 0;
	for (int i=0; i<siz; i++) {
		for (int j=i+1; j<siz; j++) {
			int br = (bt[i] & bt[j]).count();
			sol += br * (br - 1) / 2;
		}
	}
	cout << sol;
	return 0;
}