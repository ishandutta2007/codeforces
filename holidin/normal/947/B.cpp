#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int inf = 1e9;

multiset <long long> s;
long long t[N], v[N];

int main() {
    long long i, j, n, k = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    for (j = 1; j <= n; ++j)
        cin >> t[j];
    for (i = 1; i <= n; ++i) {
        long long sum = 0;
        s.insert(v[i] - k);
         k -= t[i];
        while (s.lower_bound(-k + 1) != s.begin()) {
            multiset <long long> :: iterator it = s.lower_bound(-k + 1);
            --it;
            sum += t[i] + (*it) + k;
            s.erase(it);
        }
        sum += t[i] * s.size();
        cout << sum << ' ';
    }
}