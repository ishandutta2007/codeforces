#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100005;

typedef long long llint;

int n, x, aa[MAXN], bb[MAXN];
int prof[MAXN];
pair <int, int> l[MAXN];
int bio[MAXN];
llint sol;

int main () {
	cin >> n >> x;
	for (int i=0; i<n; i++) {
		scanf("%d%d", &aa[i], &bb[i]);
		int a=aa[i], b=bb[i];
		l[i].second=i;
		if (a>=b) {
			l[i].first=0;
		} else if (2*a>=b) {
			l[i].first=b-a;
		} else {
			l[i].first=a;
		}
		if (a>=b) {
			prof[i]=b;
		} else {
			prof[i]=a;
		}
	}
	sort(l, l+n);
	reverse(l, l+n);
	for (int i=0; i<x; i++) {
		sol+=((llint) l[i].first);
	}
	for (int i=0; i<n; i++) {
		sol+=((llint) prof[i]);
	}
	cout << sol;
	return 0;
}