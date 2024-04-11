#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 500005;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		if(n <= k) printf("%d\n", k - n);
		else{
			printf("%d\n", (n - k) % 2);
		}
	}
}