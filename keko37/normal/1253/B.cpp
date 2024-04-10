#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n;
set <int> st, bio;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int prosli = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x > 0) {
            if (bio.find(x) == bio.end()) {
                st.insert(x);
                bio.insert(x);
            } else if (!st.empty()) {
                cout << -1;
                return 0;
            }
        } else {
            x = -x;
            if (st.find(x) == st.end()) {
                cout << -1;
                return 0;
            } else {
                st.erase(x);
            }
            if (st.empty()) {
                bio.clear();
                v.push_back(i - prosli);
                prosli = i;
            }
        }
    }
    if (!st.empty()) {
        cout << -1;
        return 0;
    }
    cout << v.size() << endl;
    for (auto x : v) cout << x << " ";
    return 0;
}