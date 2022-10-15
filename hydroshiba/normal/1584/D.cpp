#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

map<ii, lol> cow;

lol ask(int l, int r){
    if(r < l) return 0;
    if(cow.find(ii(l, r)) != cow.end()) return cow[ii(l, r)];

    cout << "? " << l << ' ' << r << endl;
    lol res;
    cin >> res;

    cow[ii(l, r)] = res;
    return res;
}

void solve(){
    cow.clear();

    int n;
    cin >> n;

    lol val = ask(1, n);
    int l = 1, r = n, k;

    while(l < r){
        k = (l + r) / 2;
        if(ask(1, k) == val) r = k;
        else l = k + 1;
    }

    k = (l + r) / 2;
    val = ask(1, k) - ask(1, k - 1);
    lol j = k - val;

    val = ask(1, j - 1) - ask(1, j - 2);
    lol i = j - val - 1;

    cout << "! " << i << ' ' << j << ' ' << k << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}