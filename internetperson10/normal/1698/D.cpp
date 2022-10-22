#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> ask(int l, int r) {
    cout << "? " << l << ' ' << r-1 << endl;
    vector<ll> ans(r-l);
    for(int i = 0; i < r-l; i++) {
        cin >> ans[i];
    }
    return ans;
}

void solve(int l, int r) {
    if(l == r - 1) {
        cout << "! " << l << endl;
        return;
    }
    int mid = (l + r) / 2;
    vector<ll> ans = ask(l, mid);
    int ct = 0;
    for(int g : ans) {
        if(l <= g && g < mid) ct++;
    }
    if(ct%2) solve(l, mid);
    else solve(mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        solve(1, n+1);
    }
}