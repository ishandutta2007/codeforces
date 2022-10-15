#include<bits/stdc++.h>
using namespace std;
int h[110];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>h[i];
        int ans=-2;
        while(k--)
        {
            int i;
            for(i=0;i<n-1;i++)
                if(h[i]<h[i+1])
                {
                    h[i]++;
                    break;
                }
            if(i==n-1)
                break;
            if(k==0)
                ans=i;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}