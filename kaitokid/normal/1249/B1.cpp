#include <bits/stdc++.h>

using namespace std;
int a[209],ans[209];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {int n;
        cin>>n;

        for(int i=1;i<=n;i++)
    {

         cin>>a[i];ans[i]=0;}
            for(int i=1;i<=n;i++)
            {
                if(ans[i]!=0)continue;
                int l=a[i];
                ans[i]=1;
                while(l!=i){ans[i]++;l=a[l];}
                 l=a[i];
                while(l!=i){ans[l]=ans[i];l=a[l];}
            }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    }
    return 0;
}