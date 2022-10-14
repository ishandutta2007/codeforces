#include <bits/stdc++.h>
using namespace std;
//
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m=2000000000;
	cin >> n >> k;
	for (int i = 1; i < k; i++) {
		if(n%i==0){
			int q=n/i;
			m=min(m,q*k+i);
		}
	}
	cout<<m;
}