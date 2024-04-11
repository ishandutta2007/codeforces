#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, k;

int main(){
	cin >> n;
	int px = 0;
	while(n--){
		int k;
		string t;
		cin >> k >> t;
		if(t == "East" || t == "West"){
			if(px == 20000 || px == 0){
				cout << "NO";
				return 0;
			}
		}
		else if(t == "North"){
			if(px - k < 0){
				cout << "NO";
				return 0;
			}
			px -= k;
		}
		else{
			if(px + k > 20000){
				cout << "NO";
				return 0;
			}
			px += k;
		}
	}
	if(px != 0){
		cout << "NO";
		return 0;
	}
	cout << "YES";
}