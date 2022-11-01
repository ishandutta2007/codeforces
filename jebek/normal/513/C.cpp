#include <iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int n;
long double ans,p,p1,l[10],r[10];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>l[i]>>r[i];
    for(int i=0;i<n;i++)
    {
        for(int j=l[i];j<=r[i];j++)
        {
            p=1.0/(r[i]-l[i]+1.0);
            for(int x=0;x<n;x++)
                if(x!=i && r[x]>=j)
                {
                    if(x>i)
                        p1=p*(r[x]-max(l[x]-1.0,(long double)j))/(r[x]-l[x]+1.0);
                    else
                        p1=p*(r[x]-max(l[x]-1.0,(long double)j-1.0))/(r[x]-l[x]+1.0);
                    for(int y=0;y<i;y++)
                        if(y!=x)
                            p1*=(min(r[y],(long double)j-1.0)-min(l[y]-1.0,(long double)j-1.0))/(r[y]-l[y]+1.0);
                   // cout<<p1<<endl;
                    for(int y=i+1;y<n;y++)
                        if(y!=x)
                            p1*=(min(r[y],(long double)j)-min(l[y]-1.0,(long double)j))/(r[y]-l[y]+1.0);
                    ans+=p1*(long double)j;
                   // cout<<i<<" "<<j<<" "<<x<<" "<<p1<<endl;
                }
        }
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;
}