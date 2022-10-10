#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pii> da(n), db(n), dc(n);
	da[0].first = db[0].second = (s[0] == '0');
	da[0].second = db[0].first = (s[0] == '1');
	for(int i = 1; i < n; i ++){
		if(s[i] == '0'){
			da[i].first = max(da[i - 1].first, da[i - 1].second + 1);
			da[i].second = da[i - 1].second;
			db[i].first = max(da[i - 1].first, db[i - 1].first);
			db[i].second = max({da[i - 1].first + 1, da[i - 1].second, db[i - 1].first + 1, db[i - 1].second});
			dc[i].first = max({db[i - 1].first, db[i - 1].second + 1, dc[i - 1].first, dc[i - 1].second + 1});
			dc[i].second = max(db[i - 1].second, dc[i - 1].second);
		}
		else{
			da[i].first = da[i - 1].first;
			da[i].second = max(da[i - 1].first + 1, da[i - 1].second);
			db[i].first = max({da[i - 1].first, da[i - 1].second + 1, db[i - 1].first, db[i - 1].second + 1});
			db[i].second = max(da[i - 1].second, db[i - 1].second);
			dc[i].first = max(db[i - 1].first, dc[i - 1].first);
			dc[i].second = max({db[i - 1].first + 1, db[i - 1].second, dc[i - 1].first + 1, dc[i - 1].second});
		}
	}
	cout << max({db[n - 1].first, db[n - 1].second, dc[n - 1].first, dc[n - 1].second}) << "\n";
	return 0;
}