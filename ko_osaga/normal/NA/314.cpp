#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 998244353; //1e9 + 7;//998244353;

int n;
int query(int x){
	if(x < 1 || x > n ) return 1e9;
	cout << "? " << x << endl;
	int y; cin >> y;
	return y;
}

int main(){
	cin >> n;
	int s = 0, e = n+1;
	while(e - s > 5){
		int m = (s + e) / 2;
		int x = query(m - 1);
		int y = query(m);
		int z = query(m + 1);
		if(y < min(x, z)){
			cout << "! " << m << endl;
			return 0;
		}
		if(x < y) e = m;
		else s = m;
	}
	for(int m = s; m <= e; m++){
		int x = query(m - 1);
		int y = query(m);
		int z = query(m + 1);
		if(y < min(x, z)){
			cout << "! " << m << endl;
			return 0;
		}
	}
}