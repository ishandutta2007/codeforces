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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi am(51, -1);
    for(int i = n - 1; i >= 0; i--) {
    	am[a[i]] = i;
    }
    for(int i = 0; i < q; i++) {
    	int c;
    	cin >> c;
    	cout << 1 + am[c] << ' ';
    	for(int j = 0; j <= 50; j++) {
    		if(am[j] != -1 && am[j] < am[c]) {
    			am[j]++;
    		}
    	}
    	am[c] = 0;
    }
}