#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n, x, y;
int a[MAXN], b[MAXN], cnt[MAXN], safe;
vector <int> v[MAXN];
set <pi> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        for (int i = 1; i <= n + 1; i++) {
            cnt[i] = 0;
            v[i].clear();
        }
        st.clear();
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            cnt[b[i]]++;
            v[b[i]].push_back(i);
        }
        for (int i = 1; i <= n + 1; i++) {
            if (cnt[i] == 0) safe = i;
            if (cnt[i] != 0) st.insert({-cnt[i], i});
        }
        bool moze = 1;
        while (!st.empty()) {
            int col = st.begin() -> second;
            int pos = v[col].back();
            //cout << "bla " << pos << " " << col << endl;
            if (x > 0) {
                a[pos] = col;
                //cout << "postavi " << pos << " na " << col << endl;
                v[col].pop_back();
                st.erase(st.begin());
                cnt[col]--;
                if (cnt[col]) st.insert({-cnt[col], col});
                x--;
            } else if (n - y > 0) {
                a[pos] = safe;
                //cout << "postavi " << pos << " na " << safe << endl;
                v[col].pop_back();
                st.erase(st.begin());
                cnt[col]--;
                if (cnt[col]) st.insert({-cnt[col], col});
                y++;
            } else {
                if (st.size() == 1) {
                    moze = 0;
                    break;
                }
                if (st.size() == 3 && cnt[col] == 1) {
                    int c1 = st.begin() -> second; st.erase(st.begin());
                    int c2 = st.begin() -> second; st.erase(st.begin());
                    int c3 = st.begin() -> second; st.erase(st.begin());
                    int p1 = v[c1].back(), p2 = v[c2].back(), p3 = v[c3].back();
                    a[p1] = c2; a[p2] = c3; a[p3] = c1;
                    break;
                } else {
                    int c1 = st.begin() -> second; st.erase(st.begin());
                    int c2 = st.begin() -> second; st.erase(st.begin());
                    int p1 = v[c1].back(), p2 = v[c2].back();
                    a[p1] = c2; a[p2] = c1;
                    v[c1].pop_back(); v[c2].pop_back();
                    cnt[c1]--; cnt[c2]--;
                    if (cnt[c1]) st.insert({-cnt[c1], c1});
                    if (cnt[c2]) st.insert({-cnt[c2], c2});
                }
            }
        }
        if (moze == 0) {
            int col = st.begin() -> second;
            int pos = v[col].back();
            if (cnt[col] == 1) {
                for (int i = 1; i <= n; i++) {
                    if (i != pos && b[i] != col && a[i] == safe) {
                        a[i] = col;
                        a[pos] = safe;
                        moze = 1;
                        break;
                    }
                }
            }
        }
        if (moze) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}