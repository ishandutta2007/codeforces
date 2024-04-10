#include<bits/stdc++.h>
using namespace std;
int fr[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)fr[i]=0;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            fr[x]++;
            if(fr[x]>2)ans=x;
        }
        cout<<ans<<endl;
    }

    return 0;

}