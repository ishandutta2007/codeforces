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
    int n, t, k;
    cin >> n >> t >> k;
    int l = -1;
    int r = n - 1;
    while(r - l > 1) {
    	int mid = (l + r) / 2;
    	cout << "? 1 " << mid + 1 << endl;
    	int val;
    	cin >> val;
    	if(mid + 1 - val < k) {
    		l = mid;
    	} else {
    		r = mid;
    	}
    }
    cout << "! " << r + 1 << endl;
}