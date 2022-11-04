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
    	ll a;
    	cin >> a;
    	vector<int> b;
    	while(a) {
    		b.push_back(a % 10);
    		a /= 10;
    	}
    	reverse(b.begin(), b.end());
    	int res = 1000;
    	bool there = false;
    	for(int i = b.size() - 1; i >= 0; i--) {
    		if(b[i] == 0 && there) {
    			res = min(res, (int)b.size() - i - 2);
    			break;
    		}
    		if(b[i] == 0) {
    			there = true;
    		}
    	}
    	there = false;
    	for(int i = b.size() - 1; i >= 0; i--) {
    		if(b[i] == 2 && there) {
    			res = min(res, (int)b.size() - i - 2);
    			break;
    		}
    		if(b[i] == 5) {
    			there = true;
    		}
    	}
    	there = false;
    	for(int i = b.size() - 1; i >= 0; i--) {
    		if(b[i] == 5 && there) {
    			res = min(res, (int)b.size() - i - 2);
    			break;
    		}
    		if(b[i] == 0) {
    			there = true;
    		}
    	}
    	there = false;
    	for(int i = b.size() - 1; i >= 0; i--) {
    		if(b[i] == 7 && there) {
    			res = min(res, (int)b.size() - i - 2);
    			break;
    		}
    		if(b[i] == 5) {
    			there = true;
    		}
    	}
    	cout << res << '\n';
    }
}