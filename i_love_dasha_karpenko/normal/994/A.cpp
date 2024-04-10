#include <iostream>
using namespace std;
int reader,n,m,arr[107],arr1[107];

void main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin>>arr1[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[j] == arr[i])cout << arr[i] << ' ';
		}
	}

}