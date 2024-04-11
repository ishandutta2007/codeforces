#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
typedef pair<int, int> pi;


int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ret = 1<<n;
		for(int j=1; j<=n/2-1; j++) ret += (1<<j);
		for(int j=n/2; j<=n-1; j++) ret -= (1<<j);
		cout << ret << endl;
	}
}