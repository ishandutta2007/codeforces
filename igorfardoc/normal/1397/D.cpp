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
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	if(n == 1) {
    		cout << "T\n";
    		continue;
    	}
    	sort(a.begin(), a.end());
    	int sum = 0;
    	for(int i = 0; i < n - 1; i++) {
    		sum += a[i];
    	}
    	a[n - 1] = min(a[n - 1], sum + 1);
    	sum += a[n - 1];
    	if(sum % 2 == 0) {
    		cout << "HL\n";
    	} else {
    		cout << "T\n";
    	}
    }
}