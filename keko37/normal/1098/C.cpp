#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, s;
int par[MAXN];
vector <int> v[MAXN];

void ispis (llint k) {
    cout << "Yes" << endl;
    if (k == 1) {
        for (int i=2; i<=n; i++) {
            cout << i-1 << " ";
        }
        return;
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<v[i].size(); j++) {
            par[v[i] [j]] = v[i-1] [j/k];
        }
    }
    for (int i=2; i<=n; i++) {
        cout << par[i] << " ";
    }
}

bool moze (llint k) {
    if (k == 1) {
        if (s == n*(n+1)/2) return 1;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        v[i].clear();
        v[i].push_back(i);
    }
    llint sum = n * (n+1)/2;
    llint curr = 2, siz = k;
    for (int i=n; i>curr; i--) {
        llint d = i - curr;
        if (sum - d < s) d = sum - s;
        v[i - d].push_back(i);
        v[i].clear();
        sum -= d;
        if (v[curr].size() == siz) {
            curr++;
            siz *= k;
        }
        if (sum == s) return 1;
    }
    if (sum == s) return 1;
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    if (n * (n+1) / 2 < s || moze(n-1) == 0) {
        cout << "No";
        return 0;
    }
    int low = 1, high = n-1;
    while (low < high) {
        int mid = (low + high)/2;
        if (moze(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    moze(low);
    ispis(low);
    return 0;
}