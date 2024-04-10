#include<bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int tc, n, m;
int boja[MAXN], a[MAXN], b[MAXN];
vector <int> mat, ind;
set <int> st;
vector <int> v[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        mat.clear(); ind.clear(), st.clear();
        for (int i=1; i<=3*n; i++) {
            boja[i] = 0;
            v[i].clear();
        }
        for (int i=1; i<=m; i++) {
            cin >> a[i] >> b[i];
            v[a[i]].push_back(i); v[b[i]].push_back(i);
            st.insert(i);
        }
        while (!st.empty()) {
            int e = *st.begin();
            st.erase(st.begin());
            boja[a[e]] = boja[b[e]] = 1;
            mat.push_back(e);
            for (auto sus : v[a[e]]) {
                if (st.find(sus) != st.end()) st.erase(sus);
            }
            for (auto sus : v[b[e]]) {
                if (st.find(sus) != st.end()) st.erase(sus);
            }
        }
        if (mat.size() >= n) {
            cout << "Matching\n";
            for (int i=0; i<n; i++) {
                cout << mat[i] << " ";
            }
            cout << '\n';
        } else {
            for (int i=1; i<=3*n; i++) {
                if (boja[i] == 0) ind.push_back(i);
            }
            cout << "IndSet\n";
            for (int i=0; i<n; i++) {
                cout << ind[i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}