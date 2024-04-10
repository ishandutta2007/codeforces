#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n, lo, hi;
string s;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    lo = 0, hi = n-1;
    while (lo < hi) {
        if (s[lo] == ')') {
            lo++;
            continue;
        }
        if (s[hi] == '(') {
            hi--;
            continue;
        }
        v.push_back(lo + 1);
        v.push_back(hi + 1);
        lo++; hi--;
    }
    sort(v.begin(), v.end());
    if (v.size() == 0) {
        cout << 0;
        return 0;
    }
    cout << 1 << endl;
    cout << v.size() << endl;
    for (auto x : v) cout << x << " ";
    return 0;
}