#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 0;

int n;
vector<int> a, b;

int bestCandidate (vector<int> &t, int curr) {
    int pos = 0;
    for (int i = 0; i < t.size(); i++) {
        if (abs(curr - t[i]) <= abs(curr - t[pos])) {
            pos = i;
        }
    } 
    return pos;
}

ll sprawdz () {
    vector<int> canla = { 0, bestCandidate(b, a[0]), n-1 };
    vector<int> canpa = { 0, bestCandidate(b, a[n-1]), n-1 };

    ll best = LLONG_MAX;
    for (int i : canla) {
        for (int j : canpa) {
            ll ans = (ll)abs(a[0] - b[i]) + (ll)abs(a[n-1] - b[j]);

            if (i > 0 and j > 0)
                ans += (ll)abs(b[0] - a[bestCandidate(a, b[0])]);
            
            if (i < n-1 and j < n-1)
                ans += (ll)abs(b[n-1] - a[bestCandidate(a, b[n-1])]);

            best = min(ans, best);
        }
    }

    return best;

}

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &n);
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        printf("%lld\n", sprawdz());
    }

    return 0;
}