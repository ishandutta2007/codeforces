/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, h;
    cin>>n>>h;

    int ans=0, a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<n; i++)
    {
        if(a[i]>h) ans+=2;
        else ans+=1;
    }

    cout<<ans<<endl;

    return 0;
}