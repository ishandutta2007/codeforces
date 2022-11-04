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
    	ll max1 = 0;
    	ll min1;
    	vi a(n);
    	ll sum = 0;
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		max1 += (a - 1) / k + 1;
    		sum += a;
    	}
    	min1 = (sum - 1) / k + 1;
    	cout << min1 << ' ' << max1 << '\n';
    }
}