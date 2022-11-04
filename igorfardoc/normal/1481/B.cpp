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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	bool ok = true;
    	int last1 = -1;
    	for(int i = 0; i < k; i++) {
    		int last = -1;
    		for(int j = 0; j < n - 1; j++) {
    			if(a[j] < a[j + 1]) {
    				++a[j];
    				last = j;
    				break;
    			}
    		}
    		if(last == -1) {
    			cout << "-1\n";
    			ok = false;
    			break;
    		}
    		last1 = last;
    	}
    	if(ok) {
    		cout << last1 + 1 << '\n';
    	}
    }
}