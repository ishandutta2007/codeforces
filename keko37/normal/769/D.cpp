#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const int MAXB = (1<<14);

llint n, k, sol;
llint l[MAXN];
llint p[MAXB];
llint t[MAXB];
vector <int> v;

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		p[l[i]]++;
	}
	for (int i=0; i<MAXB; i++) {
		if (__builtin_popcount(i)==k) v.push_back(i);
	}
	for (int i=0; i<MAXB; i++) {
		for (int j=0; j<v.size(); j++) {
			t[i]+=p[i^v[j]];
		}
	}
	for (int i=0; i<n; i++) {
		sol+=t[l[i]];
	}
	if (k==0) {
		cout << (sol-n)/2;
	} else {
		cout << sol/2;
	}
	return 0;
}