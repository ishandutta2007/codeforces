#include <iostream>

using namespace std;

bool isRestricted[1000];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < 2 * m; i++){
		int city;
		cin >> city;
		isRestricted[city - 1] = true;
	}
	int ii;
	for(ii = 0; ii < n; ii++)
		if(!isRestricted[ii])
			break;
	// m < n / 2 so i != n
	cout << n - 1 << endl;
	for(int i = 0; i < n; i++){
		if( i != ii ){
			cout << ii + 1 << " " << i + 1 << endl;
		}
	}
	return 0;
}