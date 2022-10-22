#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b)==1)cout<< "Finite\n";
        else cout<< "Infinite\n";
    }
    return 0;
}