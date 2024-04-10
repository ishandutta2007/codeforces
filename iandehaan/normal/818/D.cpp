#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<pair<int, int>> avail;
    map<int, int> stuff;
    unordered_set<int> rmvd;
    int n, a;
    cin >> n >> a;
    bool seena = false;
    int numa = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == a) {
            seena = true;
            numa++;
            vector<pair<int, int>> rmv;
            for (pair<int, int> thing : avail) {
                if (thing.first < numa) rmv.pb(thing);
                else break;
            }
            for (pair<int, int> thing : rmv) {
                avail.erase(thing);
                rmvd.insert(thing.second);
            }
        } else {
            if (!seena) {
                if (stuff.find(x) != stuff.end()) {
                    avail.erase(mp(stuff[x], x));
                    avail.insert(mp(stuff[x]+1, x));
                    stuff[x]++;
                } else {
                    stuff[x] = 1;
                    avail.insert(mp(1, x));
                }
            } else {
                if (rmvd.find(x) == rmvd.end() && stuff.find(x) != stuff.end()) {
                    avail.erase(mp(stuff[x], x));
                    avail.insert(mp(stuff[x]+1, x));
                    stuff[x]++;
                }
            }
        }
    }
    if (avail.empty()) cout << -1 << endl;
    else cout << (*(avail.begin())).second << endl;
}