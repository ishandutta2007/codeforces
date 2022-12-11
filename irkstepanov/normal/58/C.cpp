#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const int nmax = 100500;

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    vector<int> cnt(nmax);
    for (int i = 1; i < nmax; ++i) {
    	cnt[i] = n;
    }
    for (int i = 0; i < n; ++i) {
    	int j = i;
    	if (j > (n - 1) / 2) {
    		j = n - j - 1;
    	}
    	int val = a[i] - j;
    	if (val >= 1) {
    		--cnt[val];
    	}
    }

    int ans = cnt[1];
    for (int i = 1; i < nmax; ++i) {
    	ans = min(ans, cnt[i]);
    }
    cout << ans << "\n";

}