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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    sort(all(a));

    int ptr = 0;
    int sub = 0;
    while (k--) {
    	if (ptr == n) {
    		cout << "0\n";
    		continue;
    	}
    	while (ptr < n && a[ptr] - sub == 0) {
    		++ptr;
    	}
    	if (ptr == n) {
    		cout << "0\n";
    		continue;
    	}
    	cout << a[ptr] - sub << "\n";
    	sub = a[ptr];
    	++ptr;
    }

}