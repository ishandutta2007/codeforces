#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 200005;

int n, m;
int l[MAXN];
string t, p, s;

bool f (int len) {
	s=t;
	for (int i=0; i<len; i++) {
		s[l[i]-1]='.';
	}
	int ind=-1;
	for (int i=0; i<m; i++) {
		ind++;
		while (ind<n && s[ind]!=p[i]) ind++;
		if (ind==n) return 0;
	}
	return 1;
}

int main () {
	cin >> t >> p;
	n=t.size();
	m=p.size();
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	int low=0, high=n, mid;
	while (low<high) {
		mid=(low+high+1)/2;
		if (f(mid)) {
			low=mid;
		} else {
			high=mid-1;
		}
	}
	cout << low;
	return 0;
}