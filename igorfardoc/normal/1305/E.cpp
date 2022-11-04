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
    int n, m;
    cin >> n >> m;
    if((n - 1) * (n - 2) / 2 < m) {
    	cout << -1;
    	return 0;
    }
    if(n == 1) {
    	cout << 1;
    	return 0;
    }
    if(n == 2) {
    	cout << "1 2";
    	return 0;
    }
    vi a(n);
    a[0] = 1;
    a[1] = 2;
    for(int i = 2; i < n; i++) {
    	if(m == 0) {
    		a[i] = 1000000000 - (n - 1 - i) * 10001;
    		continue;
    	}
    	if(m >= i / 2) {
    		m -= i / 2;
    		a[i] = a[i - 1] + 1;
    		continue;
    	}
    	int need = m * 2;
    	a[i] = a[i - 1] + a[i - need];
    	m = 0;
    }
    if(m > 0) {
    	cout << -1;
    	return 0;
    }
    for(int i = 0; i < n; i++) {
    	cout << a[i] << ' ';
    }
}