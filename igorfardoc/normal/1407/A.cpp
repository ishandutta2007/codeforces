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
    	int am1 = 0;
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		am1 += a;
    	}
    	int need = 0;
    	int count = n / 2;
    	if(am1 > n / 2) {
    		need = 1;
    		if(n / 2 % 2 == 1) {
    			++count;
    		}
    	}
    	cout << count << '\n';
    	for(int i = 0; i < count; i++) {
    		cout << need << ' ';
    	}
    	cout << '\n';
    }
}