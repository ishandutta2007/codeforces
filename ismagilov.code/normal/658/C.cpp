#include <iostream>
using namespace std;

int main() {
	int n, d, h;
	cin >> n >> d >> h;
	if (min(2 * h, n) < d || h == 0 || (d < 2 && n > 2)){
		cout << -1;
		return 0;
	}
	
		if (d == h){
			for (int i = 1; i <= h; i++){
				cout << i << ' ' << i+1 << endl;
			}
			for (int i = h + 2; i <= n; i++){
				cout << 2 << ' ' << i << endl;
			}
		}
		else{
			for (int i = 1; i <= h; i++){
				cout << i << ' ' << i+1 << endl;
			}
			cout << 1 << ' ' << h+2 << endl;
			for (int i = h + 2; i <= d; i++){
				cout << i << ' ' << i+1 << endl;
			}
			for (int i = d + 2; i <= n; i++){
				cout << 1 << ' ' << i << endl;
			}
		}
	
	return 0;
}