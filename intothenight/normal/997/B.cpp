#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<bool>> broken(9, vector<bool>(49));
	for(int x = 0; x < 9; x ++) for(int y = 0; y < 49; y ++){
		for(int xx = 0; xx < 9; xx ++) for(int yy = 0; yy < 49; yy ++){
			if(4 * x + 9 * y > 4 * xx + 9 * yy && (4 * (x - xx) + 9 * (y - yy)) % 49 == 0){
				broken[x][y] = true;
			}
		}
	}
	ll res = 0;
	for(int x = 0; x < 9; x ++) for(int y = 0; y < 49; y ++){
		if(!broken[x][y] && x + y <= n){
			res += n - x - y + 1;
		}
	}
	cout << res;
	return 0;
}