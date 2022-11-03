#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    double l,v1,v2;
    cin >> n >> l >> v1 >> v2 >> k;
    int p = 2*((int)((n+k-1)/k))-1;
    cout << setprecision(9) << (v1+p*v2)/(v2+p*v1)*l/v2;
}