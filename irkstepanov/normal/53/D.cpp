#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
    	cin >> b[i];
    }

    vector<int> ans;

    int ptr = 0;
    while (ptr < n) {
    	if (a[ptr] == b[ptr]) {
    		++ptr;
    		continue;
    	}
    	int j = ptr + 1;
    	while (b[j] != a[ptr]) {
    		++j;
    	}
    	while (j > ptr) {
    		ans.pb(j - 1);
    		swap(b[j - 1], b[j]);
    		--j;
    	}
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
    	cout << ans[i] + 1 << " " << ans[i] + 2 << "\n";
    }

}