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
    	int w, h, n;
    	cin >> w >> h >> n;
    	int res1 = 1;
    	int res2 = 1;
    	while(w % 2 == 0) {
    		w /= 2;
    		res1 *= 2;
    	}
    	while(h % 2 == 0) {
    		h /= 2;
    		res2 *= 2;
    	}
    	if(res1 * res2 >= n) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}