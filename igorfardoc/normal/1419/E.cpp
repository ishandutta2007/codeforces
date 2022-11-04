#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int _gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return _gcd(b, a % b);
}

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
    	map<int, int> pr;
    	int n1 = n;
    	int i = 2;
    	while(i * i <= n1) {
    		while(n1 % i == 0) {
    			++pr[i];
    			n1 /= i;
    		}
    		++i;
    	}
    	if(n1 != 1) {
    		++pr[n1];
    	}
    	set<int> div;
    	for(int i = 1; i * i <= n; i++) {
    		if(n % i == 0) {
    			if(i != 1) {
    				div.insert(i);
    			}
    			if(n / i != 1) {
    				div.insert(n / i);
    			}
    		}
    	}
    	vi ans;
    	ans.push_back(n);
    	div.erase(div.find(n));
    	for(const auto& el : pr) {
    		int now = el.first;
    		for(int i = 0; i < el.second; i++) {
    			auto it = div.find(now);
    			if(it != div.end()) {
    				ans.push_back(now);
    				div.erase(it);
    			}
    			now *= el.first;
    		}
    		vi to_del;
    		/*for(const auto& el1 : div) {
    			if(el1 % el.first == 0) {
    				to_del.push_back(el1);
    				ans.push_back(el1);
    			}
    		}*/
    		for(auto it = div.rbegin(); it != div.rend(); ++it) {
    			if(*it % el.first == 0) {
    				to_del.push_back(*it);
    				ans.push_back(*it);
    			}
    		}
    		for(const auto& el1 : to_del) {
    			div.erase(div.find(el1));
    		}
    	}
    	int am = 0;
    	for(int i = 0; i < ans.size(); i++) {
    		if(_gcd(ans[i], ans[(i + 1) % ans.size()]) == 1) {
    			++am;
    		}
    	}
    	for(int i = 0; i < ans.size(); i++) {
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
    	cout << am << '\n';
    }
}