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
    	int n, a, b;
    	cin >> n >> a >> b;
    	vi mass(n);
    	set<int> all;
    	for(int i = 1; i <= n; i++) {
    		all.insert(i);
    	}
    	mass[0] = a;
    	mass[n - 1] = b;
    	all.erase(all.find(a));
    	all.erase(all.find(b));
    	bool ok = true;
    	for(int i = 1; i < n / 2; i++) {
    		auto it = all.end();
    		--it;
    		if(*it < a) {
    			ok = false;
    			break;
    		}
    		mass[i] = *it;
    		all.erase(it);
    	}
    	if(ok) {
    		for(int i = n / 2; i < n - 1; i++) {
    			auto it = all.begin();
    			if(*it > b) {
    				ok = false;
    				break;
    			}
    			mass[i] = *it;
    			all.erase(it);
    		}
    	}
    	if(!ok) {
    		cout << "-1\n";
    	} else {
    		for(const auto& el : mass) {
    			cout << el << ' ';
    		}
    		cout << '\n';
    	}
    }
}