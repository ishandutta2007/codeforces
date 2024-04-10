    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
     
    int n, m;
    int a[105][105], r[105], c[105], r2[105], c2[105];
     
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(nullptr);
    	cout.tie(nullptr);
    	cerr.tie(nullptr);
    	
    	cin >> n >> m;
    	
    	fill(r, r+n, 1);
    	fill(c, c+m, 1);
    	
    	for (int i=0; i<n; i++) {
    		for (int j=0; j<m; j++) {
    			cin >> a[i][j];
    			r[i] &= a[i][j];
    			c[j] &= a[i][j];
    		}
    	}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				r2[i] |= r[i] & c[j];
				c2[j] |= r[i] & c[j];
			}
		}
    	
    	for (int i=0; i<n; i++) {
    		for (int j=0; j<m; j++) {
    			if (a[i][j] != (r2[i] | c2[j])) {
    				cout << "NO\n";
    				return 0;
    			}
    		}
    	}
    	
    	cout << "YES\n";
    	for (int i=0; i<n; i++) {
    		for (int j=0; j<m; j++) {
    			cout << (r[i] & c[j]) << " \n"[j == m-1];
    		}
    	}
    }