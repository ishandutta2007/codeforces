#include<bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

int n, siz, len = 1, mx;
int a[MAXN], sum[MAXN];
map <int, int> mp;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> siz;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto par : mp) {
        v.push_back(par.second);
    }
    siz = 8 * siz / n;
    while (siz) {
        len *= 2;
        if (len >= v.size()) {
            cout << 0 << endl;
            return 0;
        }
        siz--;
    }
    for (int i=0; i<v.size(); i++) {
        sum[i] = (i == 0 ? 0 : sum[i-1]) + v[i];
        if (i - len + 1 >= 0) {
            int val;
            if (i - len + 1 == 0) val = sum[i]; else val = sum[i] - sum[i - len];
            mx = max(mx, val);
        }
    }
    cout << sum[(int) v.size() - 1] - mx << endl;
    return 0;
}