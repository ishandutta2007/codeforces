#include <bits/stdc++.h>

using namespace std;
int n, m, x;
int main()
{
cin>>n>>m;

    if(n>m)
    {
        int aux=n;
        n=m;
        m=aux;
    }
    x=m-n;
    if(x>n)
    {
        cout<<n;
    }
    else{
        n-=x;
        cout<<x+(2*n)/3;

    }

    return 0;
}