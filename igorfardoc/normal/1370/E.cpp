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
    string s, t;
    cin >> s >> t;
    int am0 = 0;
    int am1 = 0;
    for(int i = 0; i < n; i++) {
    	am0 += s[i] == '1';
    	am1 += t[i] == '1';
    }
    if(am0 != am1) {
    	cout << -1;
    	return 0;
    }
    set<int> s0, s1;
    for(int i = 0; i < n; i++) {
    	if(s[i] == t[i]) {
    		continue;
    	}
    	if(s[i] == '0') {
    		s0.insert(i);
    	} else {
    		s1.insert(i);
    	}
    }
    int ans = 0;
    while(!s0.empty()) {
    	int need = 0;
    	++ans;
    	if(*(s1.begin()) < *(s0.begin())) {
    		need = 1;
    	}
    	int pos = -1;
    	while(true) {
    		set<int>* now;
    		set<int>* other;
    		if(need == 0) {
    			now = &s0;
    			other = &s1;
    		} else {
    			now = &s1;
    			other = &s0;
    		}
    		auto it = now->lower_bound(pos);
    		if(it == now->end()) {
    			break;
    		}
    		int pos1 = *it;
    		auto it2 = other->lower_bound(pos1);
    		if(it2 == other->end()) {
    			break;
    		}
    		pos = *it2;
    		now->erase(it);
    		other->erase(it2);
    	}
    }
    cout << ans;
}