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
    	vi a(7);
    	for(int i = 0; i < 7; i++) {
    		cin >> a[i];
    	}
    	cout << a[0] << ' ' << a[1] << ' ';
    	if(a[2] == a[0] + a[1]) {
    		cout << a[3];
    	} else {
    		cout << a[2];
    	}
    	cout << '\n';
    }
}