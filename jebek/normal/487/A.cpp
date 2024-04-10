#include <iostream>
#include<algorithm>

using namespace std;

int a[2],b[2],c[2],ans,x,y,z,f1,f2;

int main()
{
    ans=2000000000;
    for(int i=0;i<2;i++)
        cin>>a[i]>>b[i]>>c[i];
    cin>>x>>y>>z;
    for(int i=0;i<=200;i++)
        for(int j=0;j<=200;j++)
        {
            if(b[0]+i<=c[1])
                continue;
            f1=b[0]+i-c[1];
            f2=max(0,b[1]-c[0]-j);
            if(f2==0)
            {
                ans=min(ans,i*y+z*j);
                continue;
            }
            f1=(a[1]+f1-1)/f1;
            if(f2*f1<a[0])
                ans=min(ans,i*y+z*j);
            else
                ans=min(ans,i*y+z*j+(f2*f1+1-a[0])*x);
        }
    cout<<ans<<endl;
}