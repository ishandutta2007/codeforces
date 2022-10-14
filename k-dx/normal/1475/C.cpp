#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int A = 200005;

vector<int> L[A], R[A];

int main () {
	int ttt;
    cin >> ttt;
	while (ttt--) {
        int a, b, k;
        cin >> a >> b >> k;
        vector<pair<int,int>> pairs(k);

        for (int i = 0; i < k; i++) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < k; i++) {
            cin >> pairs[i].second;
        }

        for (int i = 0; i < k; i++) {
            L[pairs[i].first].pb(pairs[i].second);

            R[pairs[i].second].pb(pairs[i].first);
        }

        ll wynik = 0;
        for (int i = 0; i < k; i++) {
            auto p = pairs[i];
            wynik += k - 1 - (L[p.first].size() - 1) - (R[p.second].size() - 1);
        }

        fill(L, L + a + 1, vector<int>(0));
        fill(R, R + b + 1, vector<int>(0));


        cout << wynik/2 << "\n";
		
	}
	return 0;
}