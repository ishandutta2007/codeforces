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
    	int now = 1;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
  		bool ok = true;
    	for(int i = 0; i < n; i++) {
    		if(i != 0 && a[i] == 0 && a[i - 1] == 0) {
    			ok = false;
    			break;
    		}
    		if(i != 0 && a[i] == 1 && a[i - 1] == 1) {
    			now += 5;
    			continue;
    		}
    		if(a[i] == 0) {
    			continue;
    		}
    		now++;
    	}
    	if(!ok) {
    		cout << "-1\n";
    	} else {
    		cout << now << '\n';
    	}
    }
}