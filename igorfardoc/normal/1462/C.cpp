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
    	int x;
    	cin >> x;
    	if(x > 45) {
    		cout << "-1\n";
    		continue;
    	}
    	for(int i = 1; i <= 9; i++) {
    		if(45 - (9 - i) * (9 - i + 1) / 2 >= x) {
    			int need = x;
    			for(int j = 0; j < i; j++) {
    				int ost = i - j - 1;
    				int can = 45 - (9 - ost) * (9 - ost + 1) / 2;
    				cout << need - can;
    				need = can;
    			}
    			break;
    		}
    	}
    	cout << '\n';
    }
}