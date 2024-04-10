#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int q(int r) {
	cout << "? 1 " << r + 1 << endl;
	int res;
	cin >> res;
	return r + 1 - res;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, t;
    cin >> n >> t;
    vector<int> a;
    int was = false;
    while(t--) {
    	int k;
    	cin >> k;
    	if(!was) {
    		a.push_back(0);
		    for(int i = 19; i < n; i += 20) {
		    	a.push_back(q(i));
		    }
		    was = true;
		}
    	int pos = lower_bound(a.begin(), a.end(), k) - a.begin() - 1;
    	int l = pos * 20 - 1;
    	int r = min(n - 1, l + 20);
    	while(r - l > 1) {
    		int mid = (l + r) / 2;
    		int am = q(mid);
    		if(am >= k) {
    			r = mid;
    		} else {
    			l = mid;
    		}
    	}
    	cout << "! " << r + 1 << endl;
    	for(int i = pos + 1; i < a.size(); i++) {
    		a[i]--;
    	}
    }
}