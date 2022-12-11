#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    set<int> s;
    for (int i = 1; i <= 100; ++i) {
    	s.insert(i);
    }

    while (n--) {
    	set<int> nx;
    	int k;
    	cin >> k;
    	while (k--) {
    		int x;
    		cin >> x;
    		nx.insert(x);
    	}
    	set<int> ans;
    	for (int x : s) {
    		if (!nx.count(x)) {
    			continue;
    		}
    		ans.insert(x);
    	}
    	s = ans;
    }

    for (int x : s) {
    	cout << x << " ";
    }
    cout << "\n";

}