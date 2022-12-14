#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		int cx[2] = {0, 0}, cy[2] = {0, 0};
		for(int i = 0; i < (int)s.size(); ++i){
			if(s[i] == 'R') ++cx[1];
			else if(s[i] == 'L') ++cx[0];
			else if(s[i] == 'U') ++cy[1];
			else ++cy[0];
		}
		int f = 1;
		if(x > 0 && cx[1] < x) f = 0;
		if(x < 0 && cx[0] < -x) f = 0;
		if(y > 0 && cy[1] < y) f = 0;
		if(y < 0 && cy[0] < -y) f = 0;
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}