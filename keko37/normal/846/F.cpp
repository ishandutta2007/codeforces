#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

typedef long long llint;

const llint MAXN = 1000005;

llint n, sol, res;
llint l[MAXN];
set <int> s;
vector <int> v[MAXN];

int nadi (int ind) {
	int res=upper_bound(v[l[ind]].begin(), v[l[ind]].end(), ind)-v[l[ind]].begin();
	if (res==v[l[ind]].size()) return n; return v[l[ind]] [res];
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		v[l[i]].push_back(i);
		s.insert(l[i]);
		res+=s.size();
	}
	for (int i=0; i<n; i++) {
		sol+=res;
		res-=nadi(i)-i;
	}
	printf("%.7f", ((double) (2*sol-n))/(n*n));
	return 0;
}