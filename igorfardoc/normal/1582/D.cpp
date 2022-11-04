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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	int last = n - 1;
    	if(n % 2 == 1) {
    		last = n - 4;
    	}
    	for(int i = 0; i + 1 <= last; i+=2) {
    		cout << a[i + 1] << ' ' << -a[i] << ' ';
    	}
    	if(n % 2 == 1) {
    		int fir = n - 3;
	    	int sec = n - 2;
	    	int thi = n - 1;
	    	if(a[fir] == -a[sec]) {
	    		swap(sec, thi);
	    	}
	    	if(a[fir] == -a[sec]) {
	    		swap(fir, thi);
	    	}
	    	vi ans(3);
	    	ans[fir - n + 3] = a[thi];
	    	ans[sec - n + 3] = a[thi];
	    	ans[thi - n + 3] = -a[fir] - a[sec];
    		cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    	}
    	cout << '\n';
    }
}