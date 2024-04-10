#include <bits/stdc++.h>

using namespace std;

#define int long long

int bp(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return bp(x * x, y / 2);
    }
    else {
        return bp(x * x, y / 2) * x;
    }
}

int sz(int ii) {
    int l = 0;
    while (ii > 0) {
        ii /= 10;
        l++;
    }
    return l;
}

string get(int k) {
    string s = "";
    while (k > 0) {
        s += ((k % 10) +'0');
        k /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> a, b;
    a.push_back(1);
    b.push_back(0);
    b.push_back(1);
    int s = 1, i = 2, z = 1;
    while (i < 100000) {
        z += sz(i);
        s += z;
        a.push_back(z);
        b.push_back(s);
        i++;
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int tmp = 1, i = 1;
        while (tmp + a[i - 1] <= x) {
            tmp += a[i - 1];
            i++;
        }
        x -= tmp;
        x++;
        int k = 1;
        int ans = 0;
        while (true) {
            x -= sz(k);
            if (x <= 0) {
                x += sz(k);
                string s = get(k);
                ans = (s[x - 1] - '0');
                break;
            }
            k++;
        }
        cout << ans << endl;
    }
}