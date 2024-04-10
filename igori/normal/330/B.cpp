#include <iostream>

using namespace std;
typedef long long ll;
ll cnt[3000];
int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y]++;
    }
    for (int i = 1; i<= n; i++)
    {
        if (cnt[i] == 0)
        {
            cout << n - 1 << endl;
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    cout << i << " " << j << endl;
                }
            }
            return 0;
        }
    }
}