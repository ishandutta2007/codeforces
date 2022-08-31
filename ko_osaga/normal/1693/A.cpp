#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tc; cin >> tc;
	for(int i = 0; i < tc; i++){
		int n; cin >> n;
		lint possum = 0;
		bool ok = 1;
		for(int j = 0; j < n; j++){
			lint x; 
			cin >> x;
			if(x < 0){
				if(possum < -x) ok = 0;
				possum += x;
			}
			else{
				if(possum == 0 && x > 0 && j > 0) ok = 0;
				possum += x;
			}
		}
		if(possum) ok = 0;
		cout << (ok ? "Yes" : "No") << "\n";
	}
}