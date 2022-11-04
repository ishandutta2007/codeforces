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
    vector<vector<char>> a(n, vector<char>(n, '.'));
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	int start = 0;
    	if(i % 2 == 1) {
    		start = 1;
    	}
    	for(int j = start; j < n; j+=2) {
    		a[i][j] = 'C';
    		++ans;
    	}
    }
    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		cout << a[i][j];
    	}
    	cout << '\n';
    }

}