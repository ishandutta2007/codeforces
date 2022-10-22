#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--)
    {int x;
        cin>>x;
        if(x==2){cout<<2<<"\n";continue;}
        if(x%2==1){cout<<1<<"\n";continue;}
        cout<<0<<"\n";
    }
    return 0;
}