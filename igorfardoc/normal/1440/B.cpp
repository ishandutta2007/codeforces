#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
 		int n, k;
 		cin >> n >> k;
 		ll sum = 0;
 		vi a(n * k);
 		for(int i = 0; i < n * k; i++) {
 			cin >> a[i];
 		}
 		for(int i = 0; i < k; i++) {
 			sum += a[n * k - (n / 2 + 1) - i * (n / 2 + 1)];
 		}
 		cout << sum << '\n';
 	}
}