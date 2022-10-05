#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n < 15){ cout << "NO\n"; continue; }
		int can = 0;
		for(int i = 15; i <= 20; i++){
			if((n - i) % 14 == 0){ can = 1; break; }
		}
		cout << (can ? "YES\n" : "NO\n");
	}

}