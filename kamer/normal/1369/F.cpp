#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

bool canWin(ll s, ll e) {
    if (e % 2 == 1) {
        if (s % 2 == 1) {
            return false;
        } else {
            return true;
        }
    }

    if (e == 2) {
        if (s == 1) {
            return true;
        } else {
            return false;
        }
    }

    ll k = e / 2;
    if (s <= e && s > k) {
        if (s % 2 == 0) {
            return false;
        } else {
            return true;
        }
    }

    ll t = (k / 2) + 1;
    if (k >= s && s >= t) {
        return true;
    }

    return canWin(s, t - 1);
}

bool canLose(ll s, ll e) {
    ll k = e / 2;
    if (s <= e && s > k) {
        return true;
    }
    return canWin(s, k);
}

int main(void) {
    ll t;
    cin >> t;
    vector<bool> forceLose(t);
    vector<bool> forceWin(t);
    for (ll i = 0; i < t; i++) {
        ll s, e;
        cin >> s >> e;
        forceLose[i] = canLose(s, e);
        forceWin[i] = canWin(s, e);
    }

    if (t == 1) {
        if (forceWin[0]) cout << "1 ";
        else cout << "0 ";
        if (forceLose[0]) cout << "1\n";
        else cout << "0\n";
        return 0;
    }

    bool first = true, second = false;
    for (ll i = 0; i < t; i++) {
        if (!first && !second) {
            break;
        }
        bool nextFirst = false, nextSecond = false;
        if (first) {
            if (forceWin[i]) nextSecond = true;
            if (forceLose[i]) nextFirst = true;
        }
        if (second) {
            if (!forceWin[i]) nextSecond = true;
            if (!forceLose[i]) nextFirst = true;
        }
        first = nextFirst, second = nextSecond;
    }

    if (second) cout << "1 ";
    else cout << "0 ";
    if (first) cout << "1\n";
    else cout << "0\n";
}