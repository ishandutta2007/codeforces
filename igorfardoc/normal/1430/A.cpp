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
    	bool ok = false;
    	for(int i = 0; i <= n / 7; i++) {
    		for(int j = 0; j <= (n - i * 7) / 5; j++) {
    			if((n - i * 7 - j * 5) % 3 == 0) {
    				ok = true;
    				cout << (n - i * 7 - j * 5) / 3 << ' ' << j << ' ' << i << '\n';
    				break;
    			}
    		}
    		if(ok) {
    			break;
    		}
    	}
    	if(!ok) {
    		cout << "-1\n";
    	}
    }
}