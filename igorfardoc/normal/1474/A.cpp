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
    	string s;
    	cin >> s;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		a[i] = s[i] - '0';
    	}
    	int prev = 0;
    	for(int i = 0; i < n; i++) {
    		if(1 + a[i] != prev) {
    			prev = 1 + a[i];
    			cout << '1';
    		} else {
    			prev = a[i];
    			cout << '0';
    		}
    	}
    	cout << '\n';
    }
}