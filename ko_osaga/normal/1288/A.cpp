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
		string ans = "NO";
		for(int i=1; i<=100000; i++){
			int j = i + (b + i) / (i + 1);
			if(j <= a){
				ans = "YES";
				break;
			}
		}
		if(b <= a) ans = "YES";
		cout << ans << endl;
	}
}