#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const int nmax = 1e6 + 100;

int mind[nmax];

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 2; i < nmax; ++i) {
    	mind[i] = i;
    }

    vector<int> primes;
    for (int i = 2; i < nmax; ++i) {
    	if (mind[i] == i) {
    		primes.pb(i);
    	}
    	for (int p : primes) {
    		if (p <= mind[i] && p * i < nmax) {
    			mind[p * i] = p;
    		} else {
    			break;
    		}
    	}
    }

    int n;
    cin >> n;
    vector<int> ans;

    while (n > 1) {
    	ans.pb(n);
    	n /= mind[n];
    }
    ans.pb(1);

    for (int x : ans) {
    	cout << x << " ";
    }
    cout << "\n";

}