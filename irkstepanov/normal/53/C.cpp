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

    int i = 1, j = n;
    while (i <= j) {
    	cout << i << " ";
    	++i;
    	if (i > j) {
    		return 0;
    	}
    	cout << j << " ";
    	--j;
    	if (i > j) {
    		return 0;
    	}
    }
    cout << "\n";

}