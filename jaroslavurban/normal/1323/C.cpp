#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)

const int siz = 40010;

int main(){
	ll n;
	cin >> n;
	ll sum = 0;
	ll def_len = 0;
	ll deficit = 0;
	for (ll i = 0; i < n; ++i){
		char c;
		cin >> c;
		if (c == ')')
			deficit++;
		if (c == '(')
			deficit--;
		if (deficit == 0 && def_len){
			sum += def_len + 1;
			def_len = 0;
		}
		if (deficit > 0)
			def_len++;
	}
	if (deficit == 0)
		cout << sum << endl;
	else
		cout << -1 << endl;
}