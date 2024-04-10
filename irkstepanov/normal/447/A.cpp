/**by Stepanov Ilia**/

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    int p, n;
    cin >> p >> n;

    vector <bool> m(p);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!m[x % p]) m[x % p] = true;
        else
        {
            cout << i;
            return 0;
        }
    }

    cout << "-1";

}