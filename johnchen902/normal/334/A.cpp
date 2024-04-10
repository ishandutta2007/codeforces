#include <iostream>

using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout  << (i + 1) << " " << (2 * n - i);
		for(int j = 2; j < n; j += 2)
			cout << " " << (j * n + i + 1) << " " << ((j + 2) * n - i);
		cout << endl;
	}
	return 0;
}