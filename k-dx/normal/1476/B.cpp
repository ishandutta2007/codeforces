#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 105;

int n, k;
ld kk;
int p[N];
ll pref[N];

bool sprawdz (ll add) {
    for (int i = 2; i <= n; i++) {
        if (kk < (ld)((ld)(p[i]) / (ld)(pref[i-1]+add))) {
            return false;
        }
    }
    return true;
}

int main () {
	int ttt;
	//scanf("%d", &ttt);
    cin >> ttt;
	while (ttt--) {
		//scanf("%d %d", &n, &k);
        cin >> n >> k;
        kk = (ld)(k) / (ld)(100.0);
        for (int i = 1; i <= n; i++) {
            //scanf("%d", &p[i]);
            cin >> p[i];
            pref[i] = pref[i-1] + p[i];
        }

        ll beg = 0, mid, end = 100000000000000000;
        while (beg + 1 != end) {
            //printf("%lld %lld\n", beg, end);
            mid = (beg + end) / 2;
            if (sprawdz(mid) == true) {
                end = mid;
            }
            else {
                beg = mid;
            }
        }
        if (sprawdz(beg) == true)
            cout << beg << "\n";
        else
            cout << end << "\n";


		//printf("%d\n", );
		
	}
	return 0;
}