#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN = 200005;
const int INF = 1100000007;

long long n, sol;
vector <int> v, a, b;
map <int, int> m;

void precompute () {
	for (int i=0; i*i<INF; i++) {
		v.push_back(i*i);
		m[i*i]=1;
	}
}

int cost (int x) {
	int ind=upper_bound(v.begin(), v.end(), x)-v.begin();
	return min(x-v[ind-1], v[ind]-x);
}

int main () {
	precompute();
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		scanf("%d", &x);
		if (m[x]) {
			a.push_back(1+(x==0));
		} else {
			b.push_back(cost(x));
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a.size()>b.size()) {
		for (int i=0; i<a.size()-n/2; i++) {
			sol+=a[i];
		}
	} else {
		for (int i=0; i<b.size()-n/2; i++) {
			sol+=b[i];
		}
	}
	cout << sol;
	return 0;
}