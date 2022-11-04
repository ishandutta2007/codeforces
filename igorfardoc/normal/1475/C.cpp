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
    	int a, b, k;
    	cin >> a >> b >> k;
    	vi a1(k);
    	vi b1(k);
    	vi am1(a);
    	vi am2(b);
    	for(int i = 0; i < k; i++) {
    		cin >> a1[i];
    		--a1[i];
    		am1[a1[i]]++;
    	}
    	for(int i = 0; i < k; i++) {
    		cin >> b1[i];
    		--b1[i];
    		am2[b1[i]]++;
    	}
    	ll res = 0;
    	for(int i = 0; i < k; i++) {
    		res += k - am1[a1[i]] - am2[b1[i]] + 1;
    	}
    	cout << res / 2 << '\n';
    }
}