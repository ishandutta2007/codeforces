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
    	int n, m, k;
    	cin >> n >> m >> k;
    	int one = n / k;
    	if(one >= m) {
    		cout << m << '\n';
    		continue;
    	}
    	int need = m - one;
    	int minus = (need - 1) / (k - 1) + 1;
    	cout << one - minus << '\n';
    }
}