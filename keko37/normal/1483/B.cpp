#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int a[MAXN], prv[MAXN], nxt[MAXN];
vector <int> v;
set <int> st;

void brisi (int pos) {
    v.push_back(pos + 1);
    if (__gcd(a[prv[pos]], a[pos]) == 1) st.erase(prv[pos]);
    if (__gcd(a[pos], a[nxt[pos]]) == 1) st.erase(pos);
    if (__gcd(a[prv[pos]], a[nxt[pos]]) == 1) st.insert(prv[pos]);
    nxt[prv[pos]] = nxt[pos];
    prv[nxt[pos]] = prv[pos];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear(); st.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            prv[i] = (i - 1 + n) % n;
            nxt[i] = (i + 1) % n;
        }
        for (int i = 0; i < n; i++) {
            if (__gcd(a[i], a[nxt[i]]) == 1) st.insert(i);
        }
        int pos = 0;
        while (!st.empty() && v.size() < n - 1) {
            auto it = st.lower_bound(pos);
            if (it == st.end()) it = st.begin();
            pos = nxt[nxt[*it]];
            brisi(nxt[*it]);
        }
        if (!st.empty()) v.push_back(1 + *st.begin());
        cout << v.size() << " ";
        for (auto x : v) cout << x << " "; cout << '\n';
    }
    return 0;
}