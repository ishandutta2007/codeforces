#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		int a = 0, b = 0;
		int one = 0;
		for(auto&i:s){
			if(i == '1'){
				++one;
			}
		}
		if(one % 2){
			cout << "NO\n";
			continue;
		}
		one /= 2;
		int f = 1;
		string ansA, ansB;
		for(auto&i:s){
			if(i == '1'){
				if(one){
					++a, ++b;
					ansA += '(', ansB += '(';
					--one;
				}
				else{
					--a, --b;
					ansA += ')', ansB += ')';
				}
			}
			else{
				if(a < b){
					++a, --b;
					ansA += '(', ansB += ')';
				}
				else{
					--a, ++b;
					ansA += ')', ansB += '(';
				}
			}
			if(a < 0 || b < 0){
				f = 0; break;
			}
		}
		if(a || b) f = 0;
		if(f){
			cout << "YES\n";
			cout << ansA << '\n' << ansB << '\n';
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}