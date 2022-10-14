#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n;
llint siz[2], sum[2], sum_mx;
multiset <int> ms[2], mx, ost;

void ubaci (int val, int ind) {
    ms[ind].insert(val);
    sum[ind] += val;
}

void izbaci (int val, int ind) {
    sum[ind] -= val;
    ms[ind].erase(ms[ind].find(val));
}

void ubaci_mx (int val) {
    if (!mx.empty() && *mx.begin() < val) {
        mx.insert(val); sum_mx += val;
    } else {
        ost.insert(val);
    }
}

void izbaci_mx (int val) {
    if (mx.find(val) != mx.end()) {
        mx.erase(mx.find(val));
        sum_mx -= val;
    } else {
        ost.erase(ost.find(val));
    }
}

void upd () {
    int br = ms[1].size();
    while (mx.size() < br) {
        auto it = ost.end(); it--;
        mx.insert(*it);
        sum_mx += *it;
        ost.erase(it);
    }
    while (mx.size() > br) {
        ost.insert(*mx.begin());
        sum_mx -= *mx.begin();
        mx.erase(mx.begin());
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tip, val;
        cin >> tip >> val;
        if (val > 0) {
            ubaci(val, tip);
            ubaci_mx(val);
        } else {
            izbaci(-val, tip);
            izbaci_mx(-val);
        }
        upd();
        if (ms[0].empty()) {
            if (ms[1].empty()) {
                cout << 0 << '\n';
            } else {
                cout << sum[1] * 2 - *ms[1].begin() << '\n';
            }
        } else if (ms[1].empty()) {
            cout << sum[0] << '\n';
        } else if (*ms[0].rbegin() < *ms[1].begin()) {
            cout << sum[0] + sum[1] * 2 - *ms[1].begin() + *ms[0].rbegin() << '\n';
        } else {
            cout << sum[0] + sum[1] + sum_mx << '\n';
        }
    }
    return 0;
}