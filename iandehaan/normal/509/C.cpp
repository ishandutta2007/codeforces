#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

vector<int> lst;

void nxt(ll x) {
    //cout << "nxting on " << x << endl;
    //cout << "sze=" << lst.size() << endl;
    ll currsum = 0;
    for (int entry : lst) currsum += entry;

    ll mxsum = 9*lst.size();
    ll mnsum = 0;
    for (int i = lst.size()-1; i >= 0; i--) {
        if (lst[i] == 9) mnsum += 9;
        else {
            mnsum += lst[i] + 1;
            break;
        }
    }

    if (x > mxsum) {
        for (int i = 0; i < lst.size(); i++) {
            lst[i] = 0;
        }
        lst.pb(1);
        nxt(x);
    } else if (x >= currsum) {
        ll diff = x-currsum;
        for (int i = 0; i < lst.size(); i++) {
            ll difffrom9 = 9-lst[i];
            if (difffrom9 >= diff) {
                lst[i] += diff;
                return;
            } else {
                diff -= difffrom9;
                lst[i] = 9;
            }
        }
    } else if (x >= mnsum) {
        for (int i = 0; i < lst.size(); i++) {
            if (lst[i] != 0) {
                lst[i] = 0;
                lst[i+1]++;
                i++;
                while (lst[i] == 10) {
                    lst[i] = 0;
                    lst[i+1]++;
                    i++;
                }
                nxt(x);
                return;
            }
        }
    }
    else {
        // add one digit, continue
        for (int i = 0; i < lst.size(); i++) {
            lst[i] = 0;
        }
        lst.pb(1);
        nxt(x);

    }
}

void iteratelst() {
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] < 9) {
            lst[i]++;
            for (int j = 0; j < i; j++) lst[j] = 0;
            return;
        }
    }
    for (int i = 0; i < lst.size(); i++) {
        lst[i] = 0;
    }
    lst.pb(1);
}

void prntlst() {
    for (int i = lst.size()-1; i >= 0; i--) {
        cout << lst[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    lst.pb(1);

    for (int i = 0; i < n; i++) {
        nxt(b[i]);
        prntlst();
        iteratelst();
    }
}