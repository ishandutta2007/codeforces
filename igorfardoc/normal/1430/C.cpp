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
    	int now = n;
    	for(int i = n - 1; i > 0; i--) {
    		now = (i + now - 1) / 2 + 1;
    	}
    	cout << now << '\n';
    	now = n;
    	for(int i = n - 1; i > 0; i--) {
    		cout << now << ' ' << i << '\n';
    		now = (i + now - 1) / 2 + 1;
    	}
    }
}