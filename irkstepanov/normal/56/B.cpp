#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }

    int pos = -1;
    for (int i = 1; i <= n; ++i) {
    	if (a[i] != i) {
    		pos = i;
    		break;
    	}
    }
    if (pos == -1) {
    	cout << "0 0\n";
    	return 0;
    }

    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
    	b[i] = i;
    }

    reverse(b.begin() + pos, b.begin() + a[pos] + 1);
    if (a == b) {
    	cout << pos << " " << a[pos] << "\n";
    } else {
    	cout << "0 0\n";
    }
    
}