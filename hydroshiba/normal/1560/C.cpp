#include "bits/stdc++.h"
using namespace std;

void solve(){
	long long n;
	cin >> n;

	long long i = 0;
	for(long long step = n / 2; step > 0; step /= 2){
		while((i + step) * (i + step) < n) i += step;
	}

	long long start = i * i + 1;
	long long corner = start + i;
	
	if(n > corner) cout << i + 1 << ' ' << i + 1 - (n - corner);
	else cout << n - start + 1 << ' ' << i + 1;
	
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}