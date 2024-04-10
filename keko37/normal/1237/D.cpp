#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int INF = 1000000007;

int n;
int a[MAXN];
vector <int> v;
multiset <int> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int mx = 0, mn = INF;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if (mn * 2 >= mx) {
        for (int i=0; i<n; i++) cout << -1 << " ";
        return 0;
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<n; j++) v.push_back(a[j]);
    }
    int curr = 0;
    for (int i=0; i<n; i++) {
        if (curr == i) {
            st.insert(v[curr]);
            curr++;
        }
        while (1) {
            auto it = st.end(); it--;
            int val = *it;
            if (v[curr] * 2 < val) break;
            st.insert(v[curr]);
            curr++;
        }
        cout << curr - i << " ";
        st.erase(st.find(v[i]));
    }
    return 0;
}