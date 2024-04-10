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
    	set<int> s;
    	int nc = -1;
    	int sum = 0;
    	for(int i = 0; i < n; i++) {
    		s.insert(i);
    		int a;
    		cin >> a;
    		sum += a;
    		if(a % 2 ==1 ) {
    			nc = i;
    		}
    	}
    	bool ok = false;
    	for(int i = 2; i * i <= sum; i++) {
    		if(sum % i == 0) {
    			ok = true;
    			break;
    		}
    	}
    	if(!ok) {
    		s.erase(s.find(nc));
    	}
    	cout << s.size() << '\n';
    	for(auto el : s) {
    		cout << el + 1 << ' ';
    	}
    	cout << '\n';
    }
}