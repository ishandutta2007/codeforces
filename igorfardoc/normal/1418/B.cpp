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
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	vi l(n);
    	vi all;
    	for(int i = 0; i < n; i++) {
    		cin >> l[i];
    		if(l[i] == 	0) {
    			all.push_back(a[i]);
    		}
    	}
    	sort(all.begin(), all.end());
    	for(int i = 0; i < n; i++) {
    		if(l[i] == 0) {
    			a[i] = all[all.size() - 1];
    			all.pop_back();
    		}
    		cout << a[i] << ' ';
    	}
    	cout << '\n';
    }
}