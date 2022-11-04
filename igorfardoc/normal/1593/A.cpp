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
    	cout << max(0, max(b, c) - a + 1) << ' ';
    	cout << max(0, max(a, c) - b + 1) << ' ';
    	cout << max(0, max(b, a) - c + 1) << '\n';
    }
}