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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int need1 = (k - 1) / 2 + 1;
    int need2 = k - need1;
    int l1 = 0;
    int r1 = n - 2;
    int l2 = 1;
    int r2 = n - 1;
    if(k % 2 == 1) {
    	r1 = n - 1;
    	r2 = n - 2;
    }
    int l = 0;
    int r = 1000000000;
    while(r - l > 1) {
    	int mid = (l + r) / 2;
    	int can = 0;
    	for(int i = l1; i <= r1; i++) {
    		if(a[i] <= mid) {
    			++can;
    			i++;
    		}
    	}
    	if(can >= need1) {
    		r = mid;
    		continue;
    	}
    	can = 0;
    	for(int i = l2; i <= r2; i++) {
    		if(a[i] <= mid) {
    			++can;
    			i++;
    		}
    	}
    	if(can >= need2) {
    		r = mid;
    		continue;
    	}
    	l = mid;
    }
    cout << r;
}