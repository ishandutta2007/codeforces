#include<bits/stdc++.h>

using namespace std;

const int K = 300;

long long get(int s, int l, int r, int x, int g) {
    long long ans = 0;
    for (int i = 0; i <= l; i++) {
        if (s + i > g) {
            break;
        }
        int need = (x - (s + i) % x) % x;
        int maxr = min(r, g - (i + s));
        if (maxr >= need) {
            ans += 1 + (maxr - need) / x;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    long long ans = 0;
    int n = (int) s.size();
    vector<int> cl(n), cr(n);
    for (int i = 1; i < n; i++) {
        cl[i] = (s[i - 1] == '0' ? cl[i - 1] + 1 : 0);
    }
    for (int i = n - 2; i >= 0; i--) {
        cr[i] = (s[i + 1] == '0' ? cr[i + 1] + 1 : 0);
    }
    for (int j = 0; j < K; j++) {
        vector<int> a(n + 1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                sum += j;
            } else {
                sum -= 1;
            }
            a[i + 1] = sum;
        }
        sort(a.begin(), a.end());
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i - 1]) {
                c = 0;
            } else {
                c++;
            }
            ans += c;
        }
    }
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pos.push_back(i);
        }
    }
    for (int vl = 0; vl < (int) pos.size(); vl++) {
        for (int vr = vl; vr < (int) pos.size(); vr++) {
            int can = (vr - vl + 1) * (K + 1);
            if (can > n) {
                break;
            }
            ans += get(pos[vr] - pos[vl] + 1, cl[pos[vl]], cr[pos[vr]], vr - vl + 1, n);
            //cout << pos[vl] << " " << pos[vr] << " " << ans << endl;
            ans -= get(pos[vr] - pos[vl] + 1, cl[pos[vl]], cr[pos[vr]], vr - vl + 1, can - 1);
            //cout << pos[vl] << " " << pos[vr] << " " << ans << endl;
        }
    }
    cout << ans;
}