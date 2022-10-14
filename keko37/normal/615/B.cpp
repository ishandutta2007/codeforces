#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

long long n, m, sol;
vector <int> v[100005];
long long bio[100005];

long long f (int pos) {
	if (bio[pos]!=-1) return bio[pos];
	long long res=1;
	for (int i=0; i<v[pos].size(); i++) {
		if (v[pos] [i]<pos) res=max(res, f(v[pos] [i])+1);
	}
	bio[pos]=res;
	return res;
}

int main () {
	memset(bio, -1, sizeof bio);
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1; i<=n; i++) {
		long long bla=v[i].size()*f(i);
		if (bla>sol) sol=bla;
	}
	cout << sol;
	return 0;
}