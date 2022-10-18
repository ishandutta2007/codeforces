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
	string s;
	cin >> s;
	int x = 0;
	int y = 0;
	for (int i = 0; i < len(s); i++){
		if (s[i] == 'R'){
			x++;
		}
		if (s[i] == 'L'){
			x--;
		}
		if (s[i] == 'U'){
			y++;
		}
		if (s[i] == 'D'){
			y--;
		}
	}
	x = abs(x);
	y = abs(y);
	if ((x + y) % 2 == 1){
		cout << -1;
	}
	else{
		cout << (x + y) / 2;
	}
}