#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[110];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, q;
	cin >> q;
	while(q--) {
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		ll st = 0;
		while(st < n - 1) {
			ll mI = st;
			for(int i = st; i < n; i++)
				if(a[i] < a[mI]) mI = i;
			cout << a[mI] << " ";
			for(int i = st; i < mI - 1; i++)
				cout << a[i] << " ";
			if(st != mI){
				 a[mI] = a[mI - 1];
				st = mI;
			} else st = mI + 1;	
		}
		cout << a[n - 1] << endl;
	}
	return 0;
}