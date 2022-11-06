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
    	char c;
    	cin >> n >> c;
    	string s;
    	cin >> s;
    	int res = 2;
    	int a1 = n;
    	int a2 = -1;
    	for(int i = 2;; i++) {
    		if(n % i != 0) {
    			a2 = i;
    			break;
    		}
    	}
    	int am = 0;
    	for(int i = 0; i < n; i++) {
    		am += s[i] == c;
    	}
    	if(am == n) {
    		cout << "0\n";
    		continue;
    	}
    	for(int i = 2; i <= n; i++) {
    		bool ok = true;
    		for(int j = i - 1; j < n; j += i) {
    			if(s[j] != c) {
    				ok = false;
    				break;
    			}
    		}
    		if(ok) {
    			res = 1;
    			cout << "1\n";
    			cout << i << '\n';
    			break;
    		}
    	}
    	if(res == 2) {
    		cout << "2\n" << a1 << ' ' << a2 << '\n';
    	}
    }
}