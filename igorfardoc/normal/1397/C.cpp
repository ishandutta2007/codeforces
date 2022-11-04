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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if(n <= 3) {
    	for(int i = 0; i < 3; i++) {
    		if(i < n) {
    			cout << i + 1 << ' ' << i + 1 << '\n';
    			cout << -a[i] << '\n';
    		} else {
    			cout << "1 1\n0\n";
    		}
    	}
    	return 0;
    }
    cout << "1 " << n << '\n';
    for(int i = 0; i < n - 1; i++) {
    	cout << (ll)n * -a[i] << ' ';
    }
    cout << "0\n";
    cout << "1 " << n - 1 << '\n';
    for(int i = 0; i < n - 1; i++) {
    	cout << (ll)(n - 1) * a[i] << ' ';
    }
    cout << '\n';
    cout << n << ' ' << n << '\n';
    cout << -a[n - 1];
}