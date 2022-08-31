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
	int x, y, z;
	cin >> x >> y >> z;
	if(x + z < y) cout << "-";
	else if(y + z < x) cout << "+";
	else if(x == y && z == 0) cout << "0";
	else cout << "?";
	cout << "\n";
}