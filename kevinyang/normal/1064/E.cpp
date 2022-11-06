#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	n--;
	int low = 0;
	int high = 1e9;
	cout << 0 << " " << (int)5e8 << endl;
	string com;
	cin >> com;
	int mid = (low+high)/2;
	while(n--){
		cout << mid << " " << (int)5e8 << endl;
		string c;
		cin >> c;
		if(c==com){
			low = mid;
		}
		else{
			high = mid;
		}
		mid = (low+high)/2;
	}
	cout << low << " " << 0 << " " << high << " " << (int)1e9 << endl;
	return 0;
}