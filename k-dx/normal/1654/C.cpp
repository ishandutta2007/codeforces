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

const int N = 2e5+5;

int n;
vector<ll> t;
map<ll,int> need;

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        need.clear();

        scanf("%d", &n);
        t.resize(n);

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &t[i]);
            need[t[i]]++;
            sum += t[i];
        }

        // printf("wczytane\n");

        if (n == 1) {
            printf("YES\n");
            continue;
        }

        vector<ll> bad;
        bad.pb(sum);
        vector<ll> good;

        bool ok = true;
        while (bad.size() and (int)good.size() < n) {
            ll p = bad.back();
            bad.pop_back();

            ll p1 = p / 2LL;
            ll p2 = p - p1;

            // printf("p: %lld, p1: %lld, p2: %lld\n", p, p1, p2);

            if (need[p1] > 0) {
                need[p1]--;
                good.pb(p1);
            }
            else {
                if (p1 != 1) {
                    bad.pb(p1);
                }
                else {
                    ok = false;
                    break;
                }
            }

            if (need[p2] > 0) {
                need[p2]--;
                good.pb(p2);
            }
            else {
                if (p2 != 1) {
                    bad.pb(p2);
                }
                else {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            printf("NO\n");
        }
        else {
            sort(good.begin(), good.end());
            sort(t.begin(), t.end());

            if (good.size() != t.size()) {
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
        }

    }

    return 0;
}