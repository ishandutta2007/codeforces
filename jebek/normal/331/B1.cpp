#include <iostream>
#include<algorithm>

using namespace std;

int a[110],b[110],n,q;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]=i;
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==2)
        {
            swap(a[y],a[z]);
            b[a[z]]=z;
            b[a[y]]=y;

        }
        else
        {
            int ans=1;
            for(int i=y;i<z;i++)
                if(b[i]>b[i+1])
                    ans++;
            cout<<ans<<endl;
        }
    }
}