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
    	int a, b;
    	cin >> a >> b;
    	int n;
    	string s;
    	cin >> s;
    	n = s.size();
    	bool ok = true;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '?' && s[n - i - 1] != '?') {
    			s[i] = s[n - i - 1];
    		} else if(s[i] != '?' && s[n - i - 1] == '?') {
    			s[n - i - 1] = s[i];
    		} else if(s[i] != s[n - i - 1]) {
    			ok = false;
    			break;
    		}
    	}
    	if(!ok) {
    		cout << "-1\n";
    		continue;
    	}
    	int a1 = 0;
    	int b1 = 0;
    	for(int i = 0; i < n; i++) {
    		a1 += s[i] == '0';
    		b1 += s[i] == '1';
    	}
    	if(a1 > a || b1 > b) {
    		cout << "-1\n";
    		continue;
    	}
    	if(n % 2 == 0 && a % 2 == 1) {
    		cout << "-1\n";
    		continue;
    	}
    	if((n % 2 == 1 && a % 2 == 1 && s[n / 2] == '1') || (n % 2 == 1 && b % 2 == 1 && s[n / 2] == '0')) {
    		cout << "-1\n";
    		continue;
    	}
    	if(n % 2 == 1) {
    		if(a % 2 == 1) {
    			s[n / 2] = '0';
    		} else {
    			s[n / 2] = '1';
    		}
    	}
    	int am1 = (a - a1) / 2;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '?') {
    			if(am1 == 0) {
    				s[i] = '1';
    				s[n - i - 1] = '1';
    			} else {
    				--am1;
    				s[i] = '0';
    				s[n - i - 1] = '0';
    			}
    		}
    	}
    	cout << s << '\n';
    }
}