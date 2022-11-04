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
    	int x1, x2, y1, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	if(x1 == x2 || y1 == y2) {
    		cout << abs(x1 - x2) + abs(y1 - y2) << '\n';
    	} else {
    		cout << 2 + abs(x1 - x2) + abs(y1 - y2) << '\n';
    	}
    }
}