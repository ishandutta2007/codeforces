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
    	vi a(n), b(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i] >> b[i];
    	}
    	int l = 1;
    	int r = n + 1;
    	while(r - l > 1) {
    		int mid = (l + r) / 2;
    		int nowleft = 0;
    		for(int i = 0; i < n; i++) {
    			if(nowleft == mid) {
    				break;
    			}
    			if(b[i] >= nowleft && a[i] >= mid - 1 - nowleft) {
    				++nowleft;
    			}
    		}
    		if(nowleft == mid) {
    			l = mid;
    		} else {
    			r = mid;
    		}
    	}
    	cout << l << '\n';
    }
}