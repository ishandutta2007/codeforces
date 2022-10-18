#include <iostream>
using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	int k;
	int ans = n;
	for (int i = 0; i < n; i++){
		cin >> k;
		if (k > h){
			ans++;
		}
	}
	cout << ans;
}