#include <bits/stdc++.h>
using namespace std;

int n, k;
set<pair<int,int> > jest;

int main () {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);

		jest.insert({x,0});
		
		if(jest.count({x-1,0}) == 1) {
			jest.insert({x-1, x});
		}

		if(jest.count({x+1, 0}) == 1) {
			jest.insert({x+1, x});
		}
	}

	int rozmiar = 3*(n-2)+4;
	if(n == 1) rozmiar = 1;

	printf("%d\n", (int)(rozmiar - (int)(jest.size())));
	return 0;
}