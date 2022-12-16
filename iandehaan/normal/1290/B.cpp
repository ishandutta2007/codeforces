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

    string s;
    cin >> s;

    int see[s.size()];
    unordered_map<char, int> st;
    int ind = 0;
    for (int i = 0; i < s.size(); i++) {
        while (ind < s.size() && st.size() < 3) {
            if (st.find(s[ind]) == st.end()) st[s[ind]] = 0;
            st[s[ind]]++;
            ind++;
        }
        if (st.size() == 3) {
            ind--;
            st.erase(s[ind]);

        }
        see[i] = ind;
        //cout << i << ' ' << ind << ' ' << st.size() <<endl;

        st[s[i]]--;
        if (st[s[i]] == 0) st.erase(s[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (s[l-1] == s[r-1] && l != r && see[l-1] >= r) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}