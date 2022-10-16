#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'


vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

void solve(string s, int k) {
    while (s.size() < k) {
        s += s;
    }
    for (int i = 0; i < k; i++) {
        cout << s[i];
    }
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n - k; i++) {
        s.pop_back();
    }
    n = min(n, k);
    auto kek = z_function(s);
    string lol;
    lol.push_back(s[0]);
    for (int i = 1; i < n; i++) {
        int now = kek[i];
        if (i + now == n) {
            solve(lol, k);
        }
        if (now < i) {
            if (s[i + now] < s[now]) {
                lol.push_back(s[i]);
                continue;
            } else {
                solve(lol, k);
            }
        } else {
            lol.push_back(s[i]);
            continue;
        }
    }
    solve(lol, k);
}