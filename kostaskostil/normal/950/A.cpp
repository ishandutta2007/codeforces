#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,r,a;
    cin>>l>>r>>a;
    if (l>r)
        swap(l,r);
    if (a<=(r-l))
        cout<<2*(l+a)<<"\n";
    else
    {
        a-=(r-l);
        cout<<2*r+2*(a/2)<<"\n";
    }
    return 0;
}