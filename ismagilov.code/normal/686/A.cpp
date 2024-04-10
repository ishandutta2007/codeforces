#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
#define int long long

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	ll kol = x;
	int ans = 0;
	for (int i = 0; i < n; i++){
		char a;
		int b;
		cin >> a >> b;
		if (a == '+'){
			kol += b;
		}
		else{
			if (kol >= b){
				kol -= b;
			}
			else{
				ans++;
			}
		}
	}
	cout << kol << ' ' << ans;
}