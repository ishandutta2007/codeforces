#include <bits/stdc++.h>
using namespace std;
const int N = 4e5;
const int inf = 1e9;

multiset <int> s;
long long t[N], a[N], p[N];

int main() {
    long long i, j, n, k = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    t[0] = 1;
    for (i = 1; i <= 30; ++i)
        t[i] = t[i - 1] * 2;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i) {
        cin >> p[i];
        s.insert(p[i]);
    }
    for (i = 1; i <= n; ++i) {
        int sum = 0;
        for (j = 29; j >= 0; --j) {
            multiset <int> :: iterator it = s.lower_bound(sum + (a[i] & t[j]));
            if (it == s.end() || (*it) >= sum + (a[i] & t[j]) + t[j])
                sum += t[j] - (a[i] & t[j]);
            else
                sum += (a[i] & t[j]);
        }
        s.erase(s.lower_bound(sum));
        cout << (sum ^ a[i]) << ' ';
    }
}