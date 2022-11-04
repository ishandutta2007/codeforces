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
    	if(x == y) {
    		cout << x << '\n';
    		continue;
    	}
    	if(x > y) {
    		cout << x + y << '\n';
    		continue;
    	}
    	int need = max(0, (y - x) / x - 1);
    	x += need * x;
    	cout << (x + y) / 2 << '\n';
    }
}