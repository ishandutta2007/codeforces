#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e;
    f = a + b + c + d + e;
    if(f%5 || f <= 0)
        cout << -1;
    else 
        cout << f/5;
    return 0;
}