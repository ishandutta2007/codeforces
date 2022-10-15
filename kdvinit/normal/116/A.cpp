/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int ans=0, sum=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;

        sum-=x;
        sum+=y;

        ans=max(ans,sum);
    }

    cout<<ans<<endl;

    return 0;
}