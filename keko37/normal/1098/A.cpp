#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

int n;
int p[MAXN], s[MAXN], val[MAXN];
vector <int> v[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=2; i<=n; i++) {
        cin >> p[i];
        v[p[i]].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        val[i] = s[i];
    }
    for (int i=1; i<=n; i++) {
        if (s[i] != -1) continue;
        int a = s[p[i]];
        int cvor = MAXN;
        for (int j=0; j<v[i].size(); j++) {
            int b = s[v[i] [j]];
            int d = b - a;
            cvor = min(cvor, d);
        }
        if (cvor == MAXN) cvor = 0;
        val[i] = cvor;
        if (cvor < 0) {
            cout << -1;
            return 0;
        }
        for (int j=0; j<v[i].size(); j++) {
            int b = s[v[i] [j]];
            val[v[i] [j]] = b - a - cvor;
            if (val[v[i] [j]] < 0) {
                cout << -1;
                return 0;
            }
        }
    }
    llint sum = 0;
    for (int i=1; i<=n; i++) {
        //cout << "bla " << i << " " << val[i] << endl;
        sum += val[i];
    }
    cout << sum;
    return 0;
}