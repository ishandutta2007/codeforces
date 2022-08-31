#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXT = 270000;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	cout << n/2 + 1 << "\n";
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) cout << i/2+1 << " " << i/2+1 << "\n";
		if(i % 2 == 1) cout << i/2+2 << " " << i/2+1 << "\n";
	}
}