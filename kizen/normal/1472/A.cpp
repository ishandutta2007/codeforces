#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int x, y, N;
		cin >> x >> y >> N;
		int vx = x;
		while(vx % 2 == 0){
			vx /= 2;
		}
		int vy = y;
		while(vy % 2 == 0){
			vy /= 2;
		}
		cout << ((x / vx) * (y / vy) >= N ? "YES\n" : "NO\n");
	}
	return 0;
}