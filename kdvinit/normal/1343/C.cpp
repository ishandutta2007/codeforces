#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,cntr;
        cin>>n;
        long long int a[n],ans,add;
        cin>>a[0];
        if(a[0]<0) cntr=-1;
        if(a[0]>0) cntr=+1;
        ans=a[0];
        add=a[0];
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            //cout<<cntr<<" "<<a[i]<<" "<<ans<<" "<<add<<endl;
            if(a[i]*cntr>0)
            {
                if(a[i]>add)
                {
                    ans=ans-add+a[i];
                    add=a[i];
                }
            }
            else
            {
                cntr*=-1;
                ans+=a[i];
                add=a[i];
            }
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}