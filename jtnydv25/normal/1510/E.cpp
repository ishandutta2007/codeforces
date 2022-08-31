#include <bits/stdc++.h>
using namespace std;

#define ld long double

const ld EPS = 1e-3;

bool ld_eq(ld x, ld y){
	return abs(x - y) <= EPS;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	n /= 2;
	ld xc, yc;
	cin >> xc >> yc;
	function<ld(int, int, int)> fun = [&](int x0, int y0, int delta){
		ld ret = 0;
		// (x - xc) * (y0 + (x - x0) * delta)
		ld x3 = (x0 + 1) * (x0 + 1) * (x0 + 1) - x0 * x0 * x0;
		ld x2 = (x0 + 1) * (x0 + 1) - x0 * x0;
		{
			ld A = delta, B = y0 - (xc + x0) * delta, C = -xc * (y0 - x0 * delta);
			ret += 1000 * (A / 3 * x3 + B / 2 * x2 + C);
		}
		{
			ld P = y0 - x0 * delta;
			ld A = delta * delta / 2.;
			ld B = (P - yc) * delta;
			ld C = P * P / 2 - yc * P;
			ret += A / 3 * x3 + B / 2 * x2 + C;
		}

		return ret;
	};
	vector<map<ld, string>> mp(n + 1);
	string ans = "";
	function<void(int, int, int, ld, string)> recurse = [&](int dx, int x, int y, ld V, string S){
		if(x == n){
			if(dx == -1){
				mp[y][V] = S;
			} else{
				auto it = mp[y].lower_bound(-V);
				auto it2 = it;
				if(it != mp[y].end() && ld_eq(-V, it->first)){
					ans = S + it->second;
				}
				if(it != mp[y].end()){
					it++;
					if(it != mp[y].end() && ld_eq(-V, it->first)){
						ans = S + it->second;
					}
				}
				it = it2;
				if(it != mp[y].begin()){
					it--;
					if(it != mp[y].end() && ld_eq(-V, it->first)){
						ans = S + it->second;
					}
				}
			}
			return;
		}
		for(int dy : {-1, 1}){
			if(y + dy < 0) continue;
			char c = "()"[(dx == 1) ^ (dy == 1)];
			string S2 = S;
			if(dx == 1) S2 += c;
			else{
				reverse(S2.begin(), S2.end()); S2 += c; reverse(S2.begin(), S2.end());
			}
			ld val = V;
			int x0 = x, y0 = y, delta = dy;
			if(dx == -1){
				delta *= -1;
				y0 += dy;
				x0--;
			}
			val += fun(x0, y0, delta);
			recurse(dx, x + dx, y + dy, val, S2);
		}
	};

	
	recurse(-1, 2 * n, 0, 0, "");
	recurse(1, 0, 0, 0, "");
	cout << ans << endl;
}