#include<iostream>
#include<vector>

using namespace std;

int t, x, p, k;
vector <int> v;

int upit (int x) {
	int res=0;
	int lim=(1<<v.size());
	for (int mask=1; mask<lim; mask++) {
		int r=1;
		for (int j=0; j<v.size(); j++) {
			if (mask & (1<<j)) r*=v[j];
		}
		if (__builtin_popcount(mask)&1) res+=x/r; else res-=x/r;
	}
	return x-res;
}

void factor () {
	v.clear();
	for (int i=2; i*i<=p; i++) {
		if (p%i!=0) continue;
		v.push_back(i);
		while (p%i==0) {
			p/=i;
		}
	}
	if (p>1) v.push_back(p);
}

int kth () {
	int low=x+1, high=1e9, mid;
	while (low<high) {
		mid=(low+high)/2;
		if (upit(mid)-upit(x)>=k) {
			high=mid;
		} else {
			low=mid+1;
		}
	}
	return low;
}

int main () {
	cin >> t;
	for (int i=0; i<t; i++) {
		scanf("%d%d%d", &x, &p, &k);
		factor();
		printf("%d\n", kth());
	}
	return 0;
}