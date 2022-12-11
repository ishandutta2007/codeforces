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

    int a = 0, b = 0;
    cout << "? 0 0" << endl;
    int x;
    cin >> x;

    for (int i = 29; i >= 0; --i) {
    	cout << "? " << a + (1 << i) << " " << b + (1 << i) << endl;
    	int y;
    	cin >> y;
    	if (x != y) {
    		if (y == 1) {
    			b += (1 << i);
    		} else {
    			a += (1 << i);
    		}
    		cout << "? " << a << " " << b << endl;
    		cin >> x;
    	} else {
    		cout << "? " << a << " " << b + (1 << i) << endl;
    		cin >> y;
    		if (y == 1) {
    			a += (1 << i);
    			b += (1 << i);
    		}
    	}
    }

    cout << "! " << a << " " << b << endl;

}