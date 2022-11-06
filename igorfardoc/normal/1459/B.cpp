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
    int n;
    cin >> n;
    if(n % 2 == 0) {
    	cout << (n / 2 + 1) * (n / 2 + 1);
    	return 0;
    }
    cout << 2 * (n / 2 + 1) * (n / 2 + 2);
}