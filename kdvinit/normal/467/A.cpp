/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;

        y-=x;
        if(y>=2) ans++;
    }

    cout<<ans<<endl;

    return 0;
}