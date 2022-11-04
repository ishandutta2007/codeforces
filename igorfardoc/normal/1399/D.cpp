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
    	string s;
    	cin >> s;
    	set<int> fir;
    	set<int> sec;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '0') {
    			fir.insert(i);
    		} else {
    			sec.insert(i);
    		}
    	}
    	int ans = 0;
    	vi res(n);
    	while(!fir.empty() || !sec.empty()) {
    		set<int>* a = &fir;
    		set<int>* b = &sec;
    		int now = -1;
    		if(a->empty() || (!b->empty() && (*(a->begin()) > *(b->begin())))) {
    			swap(a, b);
    		}
    		while(!a->empty()) {
    			auto it = a->lower_bound(now);
    			if(it == a->end()) {
    				break;
    			}
    			now = *it;
    			res[*it] = ans;
    			a->erase(it);
    			swap(a, b);
    		}
    		++ans;
    	}
    	cout << ans << '\n';
    	for(const auto& el : res) {
    		cout << el + 1 << ' ';
    	}
    	cout << '\n';
    }
}