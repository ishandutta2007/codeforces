#include <bits/stdc++.h>
using namespace std;

int f(long long x, int k = 16)
{
    long long s = 0;
    for (int i = 0; i < k; i++) {
        s = 10 * s + 1;
    }
    int cnt = 0;
    while (s <= x) {
        cnt += k;
        x -= s;
    }

    if (x)
        return cnt + min(f(x, k - 1), k + f(s - x, k - 1));
    else
        return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    cout << f(n) << endl;
}