#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		cnt += a[i];
	}
	while(q--){
		int x, y; cin >> x >> y;
		if(x == 1){
			--y;
			if(a[y] == 0) ++cnt;
			else --cnt;
			a[y] = 1 - a[y];
		}
		else{
			if(cnt >= y){
				cout << "1\n";
			}
			else{
				cout << "0\n";
			}
		}
	}
	return 0;
}