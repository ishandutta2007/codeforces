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
    	ll st = 1;
    	int am = 0;
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		if(a == 1) {
    			++am;
    		} else if(a == 0) {
    			st *= 2;
    		}
    	}
    	cout << st * am << '\n';
    }
}