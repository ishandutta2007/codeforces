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
    	int n, c0, c1, h;
    	cin >> n >> c0 >> c1 >> h;
    	string s;
    	cin >> s;
    	int am0 = 0;
    	int am1 = 0;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '0') {
    			++am0;
    		} else {
    			++am1;
    		}
    	}
    	cout << min(min(c0 * am0 + c1 * am1, n * c0 + am1 * h), n * c1 + am0 * h) << '\n';
    }
}