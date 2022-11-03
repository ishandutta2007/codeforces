#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    switch(n%4){
        case 0:
            cout << 0 << endl;
            return 0;

        case 1:
            cout << min(c, min(a * 3, a + b)) << endl;
            return 0;
        case 2:
            cout << min(b, min(a * 2, c * 2)) << endl;
            return 0;
        case 3:
            cout << min(a, min(c * 3, c + b)) << endl;
            return 0;
    }


    return 0;
}