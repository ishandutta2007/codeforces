#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 2005;

int n, p;
int a[MAXN], b[MAXN * 2];
vector <int> v;

int calc (int lim) {
    int cnt = 0;
    for (int i = 0; i < n; i++) if (a[i] <= lim) cnt++;
    return cnt;
}

int get (int x) {
    int sol = 1;
    for (int i = 0; i < n; i++) {
        if (b[x + i] - i <= 0) return 0;
        sol = (llint) sol * (b[x + i] - i) % p;
    }
    return sol;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i <= 4000; i++) b[i] = calc(i);
    for (int i = 1; i <= 2000; i++) {
        if (get(i) != 0) v.push_back(i);
    }
    cout << v.size() << endl;
    for (auto x : v) cout << x << " ";
    return 0;
}