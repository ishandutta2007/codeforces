#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int l = 0, r = n + 1;
	map<int, int> mp;
	mp[0] = mp[n + 1] = (int)1e9;
	int m = n / 2;
	while(l + 3 < r){
		int lv, rv;
		if(mp[l]){
			lv = mp[l];
		}
		else{
			cout << "? " << l << '\n'; cout.flush();
			cin >> lv;
			mp[l] = lv;
		}
		if(mp[r]){
			rv = mp[r];
		}
		else{
			cout << "? " << r << '\n'; cout.flush();
			cin >> rv;
			mp[r] = rv;
		}
		cout << "? " << m << '\n'; cout.flush();
		int mv; cin >> mv;
		int ml = (l + m) / 2;
		cout << "? " << ml << '\n'; cout.flush();
		int mlv; cin >> mlv;
		int mr = (m + r) / 2;
		cout << "? " << mr << '\n'; cout.flush();
		int mrv; cin >> mrv;
		mp[m] = mv, mp[ml] = mlv, mp[mr] = mrv;
		if(mlv < mv){
			r = m; m = ml;
		}
		else if(mrv < mv){
			l = m; m = mr;
		}
		else{
			l = ml, r = mr;
		}
	}
	for(int i = max(1, l); i <= r; ++i){
		int a= (int)1e9, b, c = (int)1e9;
		cout << "? " << i << '\n'; cout.flush();
		cin >> b;
		if(i > 1){
			cout << "? " << i - 1 << '\n'; cout.flush();
			cin >> a;
		}
		if(i < n){
			cout << "? " << i + 1 << '\n'; cout.flush();
			cin >> c;
		}
		if(b < a && b < c){
			cout << "! " << i << '\n'; cout.flush();
			return 0;
		}
	}
	return 0;
}