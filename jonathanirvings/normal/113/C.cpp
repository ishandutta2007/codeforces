#include <bits/stdc++.h>
using namespace std;

const int N = 3e8;

bitset<N+1> bs;

void prec() {
	for(int i = 3 ; i*i <= N ; i += 2)
		if(!bs[i]) {
			for(int j = i*i ; j <= N ; j += (i+i))
				bs[j] = 1;
		}
}

int solve(int l,int r) {
	int ret = (l <= 2 && r >= 2);
	for(int i = 5 ; i <= r ; i += 4)
		ret += (!bs[i] && l <= i);
	return ret;
}

int main() {
	prec();
	int l, r;
	cin >> l >> r;
	cout << solve(l,r) << endl;
	return 0;
}