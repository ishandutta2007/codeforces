#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> b;
    for (int i = 0; i < 6; i++)
    {
        b.push_back(n % 2);
        n /= 2;
    }
    reverse(b.begin(), b.end());
    vector<int> a(6);
    a[0] = b[0];
    a[1] = b[5];
    a[2] = b[3];
    a[3] = b[2];
    a[4] = b[4];
    a[5] = b[1];
    reverse(a.begin(), a.end());
    int c = 0;
    for (int i = 0; i < 6; i++)
    {
        c += (1 << i) * a[i];
    }
    cout << c << "\n";
}