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
    	int a, b, c;
    	cin >> a >> b >> c;
    	if((a + (ll)b * 2 + (ll)c * 3) % 2 == 0) {
    		cout << "0\n";
    	} else {
    		cout << "1\n";
    	}
    }
}