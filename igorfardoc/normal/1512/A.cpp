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
    	vvi am(101);
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		am[a].push_back(i);
    	}
    	for(int i = 0; i <= 100; i++) {
    		if(am[i].size() == 1) {
    			cout << am[i][0] + 1 << '\n';
    		}
    	}
    }
}