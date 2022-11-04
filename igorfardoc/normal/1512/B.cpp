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
    	vector<string> a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	int x1, y1, x2, y2;
    	x1 = -1;
    	y1 = -1;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			if(a[i][j] == '*') {
    				if(x1 == -1) {
    					x1 = i;
    					y1 = j;
    				} else {
    					x2 = i;
    					y2 = j;
    				}
    			}
    		}
    	}
    	if(x1 == x2) {
    		a[(x1 + 1) % n][y1] = '*';
    		a[(x1 + 1) % n][y2] = '*';
    	} else if(y1 == y2) {
    		a[x1][(y1 + 1) % n] = '*';
    		a[x2][(y2 + 1) % n] = '*';
    	} else {
    		a[x1][y2] = '*';
    		a[x2][y1] = '*';
    	}
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			cout << a[i][j];
    		}
    		cout << '\n';
    	}
    }
}