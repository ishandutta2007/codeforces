#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 998244353;
const int MAXN = 2000005;

int main(){
	int q; cin >> q;
	while(q--){
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		int ret = 0;
		for(int i=0; i<=p; i++){
			for(int j=0; j<=f; j++){
				if(i + j <= b / 2) ret = max(ret, i * h + j * c);
			}
		}
		cout << ret << endl;
	}
}