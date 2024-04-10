#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    const int N = 1e6;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int s = abs(a - 2 * b + c);
        cout << (s % 3 > 0) << "\n";
    }
}