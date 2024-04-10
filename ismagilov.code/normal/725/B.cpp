#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;


main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	char c;
	cin >> c;
	int ans = 0;
	if (n % 4 == 1 || n % 4 == 3){
		ans += ((n) / 4) * 16; 
	}
	if (n % 4 == 2 || n % 4 == 0){
		ans += ((n - 2) / 4) * 16 + 7;; 
	}
	if (c == 'f'){
		ans += 1;
	}
	if (c == 'e'){
		ans += 2;
	}
	if (c == 'd'){
		ans += 3;
	}
	if (c == 'a'){
		ans += 4;
	}
	if (c == 'b'){
		ans += 5;
	}
	if (c == 'c'){
		ans += 6;
	}
	cout << ans;

}