#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int N = 0;

ll n;

int main () {
	int ttt;
	//scanf("%d", &ttt);
    cin >> ttt;
	while (ttt--) {
		//scanf("%d", &n);
        cin >> n;
        
        while (n % 2 == 0) {
            n >>= 1;
            //cout << n << endl;
        }

        if (n != 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
	}
	return 0;
}