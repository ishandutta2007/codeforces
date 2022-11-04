#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll q(int l, int r) {
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	ll res;
	cin >> res;
	return res;
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
		ll all = q(0, n - 1);
		int l = 0;
		int r = n - 1;
		for(int i = 30; i >= 0 && r - l > 1; i--) {
			if(r - (1 << i) > l) {
				int mid = r - (1 << i);
				ll res = q(l, mid);
				if(res == all) {
					r = mid;
				} else if(res == 0) {
					l = mid;
				}
			}
		}
		int k = r;
		ll res = q(l, k - 1);
		int am = all - res + 1;
		int j = k - am + 1;
		res = q(l, j - 1);
		l = 1;
		r = 1000000000;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			if((ll)mid * (mid - 1) / 2 >= res) {
				r = mid;
			} else {
				l = mid;
			}
		}
		int i = j - r;
		cout << "! " << i + 1 << ' '  << j + 1 << ' ' << k + 1 << endl;
	}


}