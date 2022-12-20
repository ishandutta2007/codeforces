#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

string f0, f1b, f1s, f1e;
long long t[N];

char f(int n, long long k) {
    if (k >= t[n])
        return '.';
    if (n == 0)
        return f0[k];
    if (k < f1b.size())
        return f1b[k];
    else
        k -= f1b.size();
    if (k < t[n - 1])
        return f(n - 1, k);
    else
        k -= t[n - 1];
    if (k < f1s.size())
        return f1s[k];
    else
        k -= f1s.size();
    if (k < t[n - 1])
        return f(n - 1, k);
    else
        k -= t[n - 1];
    return f1e[k];
}

int main() {
    int i, j, n, q;
    long long k;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    f1b = "What are you doing while sending \"";
    f1s = "\"? Are you busy? Will you send \"";
    f1e = "\"?";
    t[0] = f0.size();
    for (i = 1; i < N; ++i)
        t[i] = min((long long)1e18, 2 * t[i - 1] + f1b.size() + f1s.size() + f1e.size());
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> n >> k;
        cout << f(n, k - 1);
    }
}