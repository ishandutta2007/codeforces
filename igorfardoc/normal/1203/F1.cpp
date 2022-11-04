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
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> plus, minus;
    int sum = 0;
    for(int i = 0; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	if(b >= 0) {
    		plus.push_back({a, b});
    	} else {
    		minus.push_back({a, -b});
    		sum -= b;
    	}
    }
    sort(plus.begin(), plus.end());
    for(int i = 0; i < plus.size(); i++) {
    	if(plus[i].first <= r) {
    		r += plus[i].second;
    	} else {
    		cout << "NO";
    		return 0;
    	}
    }
    if(r < sum) {
    	cout << "NO";
    	return 0;
    }
    while(minus.size() > 0) {
    	int a = -1;
    	int b = -1;
    	for(int i = 0; i < minus.size(); i++) {
    		if(r - (sum - minus[i].second) >= minus[i].first) {
    			if(minus[i].second > b) {
    				b = minus[i].second;
    				a = minus[i].first;
    			}
    		}
    	}
    	sum -= b;
    	if(a == -1) {
    		cout << "NO";
    		return 0;
    	}
    	vector<pair<int, int>> minus1;
    	bool ok = false;
    	for(int i = 0; i < minus.size(); i++) {
    		if(ok || (minus[i].first != a || minus[i].second != b)) {
    			minus1.push_back(minus[i]);
    		} else {
    			ok = true;
    		}
    	}
    	minus = minus1;
    }
    cout << "YES";

}