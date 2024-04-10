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
    	int x, y;
    	cin >> x >> y;
    	if((x + y) % 2 == 1) {
    		cout << "-1 -1\n";
    	} else {
    		int need = (x + y) / 2;
    		int can = min(x, need);
    		int x1 = can;
    		need -= can;
    		cout << x1 << ' ' << need << '\n';
    	}
    }
}