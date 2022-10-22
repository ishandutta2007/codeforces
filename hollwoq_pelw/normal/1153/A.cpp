#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t, s, d;
	cin >> n >> t;
	pair<int, int> p={1e9, -1};
	for(int i=0; i<n; ++i) {
		cin >> s >> d;
		while(s<t) {
			s+=d;
		}
		p=min(pair<int,int>(s,i),p);
	}
	cout << p.second+1;

	return 0;
}