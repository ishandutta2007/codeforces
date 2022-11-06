#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll p[63];



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    p[0] = 1;
    for(int i = 1; i < 63; i++) {
    	p[i] = p[i - 1] * 2;
    }
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	ll k;
    	cin >> n >> k;
    	if(n <= 63 && p[n - 1] < k) {
    		cout << "-1\n";
    		continue;
    	}
    	int now = 0;
    	while(now < n - 62) {
    		cout << now + 1 << ' ';
    		++now;
    	}
    	while(now < n) {
    		//cout << now << endl;
    		ll here = 0;
    		for(int i = 0; i < n - now; i++) {
    			ll here1 = 1;
    			if(n - now - i - 2 > 0) {
    				here1 = p[n - now - i - 2];
    			}
    			if(here + here1 >= k) {
    				k -= here;
    				int now1 = now + i + 1;
    				for(int j = now; j < now1; j++) {
    					cout << now + now1 - j << ' ';
    				}
    				now = now1;
    				break;
    			}
    			here += here1;
    		}
    	}
    	cout << '\n';
    }
}