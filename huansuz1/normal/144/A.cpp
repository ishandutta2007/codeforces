#include<iostream>
using namespace std;
int main() {
 
	int n; cin >> n;
	int arr[n];
	int ma = -1, mi = 109, i_max = 0, i_min = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (ma < arr[i]) {
			ma = arr[i];
			i_max = i;
		}
		if (mi >= arr[i]) {
			mi = arr[i];
			i_min = i;
		}
	}


	if (i_min < i_max) cout << i_max + (n - 1 - i_min) - 1; else
	cout << i_max + (n - 1 - i_min);
	return 0;
}