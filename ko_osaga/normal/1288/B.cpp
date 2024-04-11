#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 50;
const int mod = 1e9 + 7;

int main(){
	int t; cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		cout << 1ll * a * (int)log10(b + 1) << endl;
	}
}