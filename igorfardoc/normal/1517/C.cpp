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
    vvi a(n, vi(n));
    for(int i = 0; i < n; i++) {
    	cin >> a[i][i];
    }
    for(int i = 1; i < n; i++) {
    	vector<bool> used(n, false);
    	for(int j = 0; j < n - i; j++) {  //a[i][0]
    		int up = a[i + j - 1][j];
    		if(up > i && !used[up - 1]) {
    			a[i + j][j] = up;
    			used[up - 1] = true;
    		} else {
    			a[i + j][j] = a[i + j][j + 1];
    			used[a[i + j][j] - 1] = true;
    		}
    	}
    }
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j <= i; j++) {
    		cout << a[i][j] << ' ';
    	}
    	cout << '\n';
    }
}