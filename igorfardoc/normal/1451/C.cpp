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
    	vi a(26), b(26);
    	for(int i = 0; i < n; i++) {
    		char c;
    		cin >> c;
    		a[c - 'a']++;
    	}
    	for(int i = 0; i < n; i++) {
    		char c;
    		cin >> c;
    		b[c - 'a']++;
    	}
    	bool ok = true;
    	for(int i = 0; i < 26; i++) {
    		if(a[i] < b[i] || (a[i] - b[i]) % k != 0) {
    			ok = false;
    			break;
    		}
    		if(i == 25) {
    			break;
    		}
    		a[i + 1] += a[i] - b[i];
    	}
    	if(ok) {
    		cout << "Yes\n";
    	} else {
    		cout << "No\n";
    	}
    }
}