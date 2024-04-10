#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)34;
int T, A, B, C;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> A >> B >> C;
		int t = (A + B + C) / 9;
		if((A + B + C) % 9 || min({A, B, C}) < t){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}