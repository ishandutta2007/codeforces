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
    	int n, k;
    	cin >> n >> k;
    	set<int> s;
    	for(int i = 1; i <= n; i++) {
    		s.insert(i);
    	}
    	vi a(n, -1);
    	if((n - 1) / 2 < k) {
    		cout << "-1\n";
    		continue;
    	}
    	int now = 0;
    	for(int i = 1; i < n && now < k; now++, i+=2) {
    		a[i] = *(s.rbegin());
    		s.erase(--s.end());
    	}
    	for(int i = 0; i < n; i++) {
    		if(a[i] == -1) {
    			a[i] = *(s.rbegin());
    			s.erase(--s.end());
    		}
    	}
    	for(int i = 0; i < n; i++) {
    		cout << a[i] << ' ';
    	}
    	cout << '\n';
    }
}