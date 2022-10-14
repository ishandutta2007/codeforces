#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		ll n = s.size();
		ll L = 0, U = 0, R = 0, D = 0;
		for(char c : s)
			if(c == 'L') L++;
			else if(c == 'R') R++;
			else if(c == 'U') U++;
			else if(c == 'D') D++;
		U = min(U, D);
		R = min(L, R);
		if(U == 0 && R == 0)
			cout << 0 << endl;
		else if(U == 0)
			cout << "2\nLR" << endl;
		else if(R == 0)
			cout << "2\nUD" << endl;
		else {;
			cout << 2 * (U + R) << endl;
			for(ll i = 0; i < U; i++)
				cout << "U";
			for(ll i = 0; i < R; i++)
				cout << "R";
			for(ll i = 0; i < U; i++)
				cout << "D";
			for(ll i = 0; i < R; i++)
				cout << "L";
			cout << endl;
		}
	}
}