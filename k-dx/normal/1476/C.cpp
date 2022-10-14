#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int N = 100005;

int n;
ll len[N], val[N], pref[N];
pair<ll,ll> c[N];

int main () {
	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
		scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            cin >> len[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i].first;
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i].second;
            if (c[i].first > c[i].second) swap(c[i].first, c[i].second);

            //pref[i] = pref[i-1] + len[i] - (c[i].second - c[i].first);
            //val[i] = len[i] - (c[i].second - c[i].first);
        }

        ll best = 0, akt = c[2].second - c[2].first;
        for (int i = 2; i <= n; i++) {
            //printf("%d I akt = %d\n", i, akt);
            akt += 2;

            // jesli zakonczymy na i
            best = max(best, akt + len[i] - 1);
            
            if (c[i+1].first == c[i+1].second) {
                akt = 0;
            }
            else {
                if (c[i+1].second - c[i+1].first > akt + len[i] - (c[i+1].second - c[i+1].first) - 1) {
                    akt = c[i+1].second - c[i+1].first;
                }
                else {
                    akt += len[i] - (c[i+1].second - c[i+1].first) - 1;
                }
            }
            //printf("%d II akt = %d\n", i, akt);

        }

        cout << best << "\n";
		
	}
	return 0;
}