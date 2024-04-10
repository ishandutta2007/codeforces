#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

using namespace std;

long long n, k, m;
char c;

int off[266];

int main() {
	ios_base::sync_with_stdio(false);
	scanf("%lld%c", &n, &c);
	
	off['f'] = 1;
	off['e'] = 2;
	off['d'] = 3;
	off['a'] = 4;
	off['b'] = 5;
	off['c'] = 6;

	n--;
	long long ans = 16LL * (n / 4);
	n %= 4;
	n++;
	if(n == 2 || n == 4)
		ans += 7;
	cout << ans + off[c];
}