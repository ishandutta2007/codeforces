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
    	int n;
    	cin >> n;
    	vi a(n);
    	int sum = 0;
    	int sum1 = 0;
    	int sum2 = 0;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		sum += a[i];
    		if(a[i] < 0) {
    			sum1 += abs(a[i]);
    		} else {
    			sum2 += a[i];
    		}
    	}
    	if(sum == 0) {
    		cout << "NO\n";
    		continue;
    	}
    	sort(a.begin(), a.end());
    	if(a[0] == 0 || sum1 < sum2) {
    		reverse(a.begin(), a.end());
    	}
    	cout << "YES\n";
    	for(int i = 0; i < n; i++) {
    		cout << a[i] << ' ';
    	}
    	cout << '\n';
    }
}