#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int d1=abs(a-c),d2=abs(b-d);
        if(!d1||!d2)
            cout<<d1+d2<<endl;
        else    cout<<d1+d2+2<<endl;
    }
    return 0;
}