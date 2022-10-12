#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
string s[500];
ll c1[500];
ll c2[500];
int main() {
    ll n;
    cin >> n;
    if (n <= 2)
    {
        cout << "No";
        return 0;
    }
    else
    {
        for (ll d = 2; d <= n; d++)
        {
            if (((n + 1) * n / 2) % d == 0)
            {
                cout << "Yes\n";
                cout << "1 " << d << endl;
                cout << n - 1 << " ";
                for (int i = 1; i <= n; i++)
                    if (i != d) cout << i << " ";
                return 0;
            }
        }
    }

}