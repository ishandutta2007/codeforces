#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt --){
		int n, k;
		cin >> n >> k;
		if(k % 3){
			cout << (n % 3 ? "Alice" : "Bob") << "\n";
		}
		else{
			n %= (k + 1);
			if(n == k){
				cout << "Alice\n";
			}
			else{
				cout << (n % 3 ? "Alice" : "Bob") << "\n";
			}
		}
	}
	return 0;
}