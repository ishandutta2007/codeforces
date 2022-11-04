#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int _gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return _gcd(b, a % b);
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
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	int min1 = -1;
    	vector<bool> used(n, false);
    	int id1;
    	for(int i = 0; i < n; i++) {
    		if(a[i] > min1) {
    			min1 = a[i];
    			id1 = i;
    		}
    	}
    	cout << a[id1] << ' ';
    	used[id1] = true;
    	for(int i = 1; i < n; i++) {
    		int id1;
    		int min2 = -1;
    		for(int j = 0; j < n; j++) {
    			if(used[j]) continue;
    			int here = _gcd(min1, a[j]);
    			if(here > min2) {
    				min2 = here;
    				id1 = j;
    			}
    		}
    		cout << a[id1] << ' ';
    		used[id1] = true;
    		min1 = min2;
    	}
    	cout << '\n';
    }
}