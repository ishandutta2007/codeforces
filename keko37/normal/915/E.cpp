#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

int n, q, sol;
set <pair <int, int> > s;
set <pair <int, int> > :: iterator it;

void uredi (int a, int b) {
	it=s.lower_bound(make_pair(a, 0));
	while (it!=s.end()) {
		int x = it->second;
		int y = it->first;
		if (x>b) break;
		it = s.erase(it);
		sol-=y-x+1;
		if (x<a) {
			s.insert(make_pair(a-1, x));
			sol+=a-x;
		}
		if (b<y) {
			s.insert(make_pair(y, b+1));
			sol+=y-b;
		}
	}
}

int main () {
	cin >> n >> q;
	for (int i=0; i<q; i++) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		uredi(a, b);
		if (k==1) {
			s.insert(make_pair(b, a));
			sol+=b-a+1;
		}
		printf("%d\n", n-sol);
	}
	return 0;
}