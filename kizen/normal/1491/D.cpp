#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int x, y; cin >> x >> y;
		vector<int> a, b;
		for(int i = 0; i < 31; ++i){
			if(x & (1 << i)){
				a.push_back(i);
			}
			if(y & (1 << i)){
				b.push_back(i);
			}
		}
		int cnt = (int)a.size() - (int)b.size();
		if(cnt < 0){
			cout << "NO\n";
			continue;
		}
		int pos = (int)a.size() - 1, cant = 0;
		for(int i = (int)b.size() - 1; i >= 0; --i){
			if(pos < 0 || a[pos] > b[i]){
				cant = 1;
				break;
			}
			if(a[pos] == b[i]){
				--pos; continue;
			}
			int mx;
			mx = b[i] - 1;
			mx = min(mx, cnt);
			if(mx >= 1){
				cnt -= mx; pos -= mx;
			}
			--pos;
		}
		if(cant || cnt){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}