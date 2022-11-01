#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c;
    cin >> a >> b >> c;
    c *= c+1;
    c /= 2;
    a *= c;
    cout << max((long long)0,a-b);
    return 0;
}