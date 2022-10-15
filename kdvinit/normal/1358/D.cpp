#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long int n,x;
    cin>>n>>x;
    long long int d[n+1],ans=0,dmax=0,z;
    for(long long int i=1;i<=n;i++)
    {
        cin>>d[i];
        dmax=max(dmax,d[i]);
    }

    if(x<=dmax)
    {
        z=dmax;
        ans+=(z*(z+1))/2;
        z-=x;
        ans-=(z*(z+1))/2;
        cout<<ans<<endl;
        return 0;
    }

    long long int temp=0,cntr=0,m;
    for(long long int i=1;1;i--)
    {
        if(i<1) i+=n;
        cntr+=d[i];
        temp+=((d[i])*(d[i]+1))/2;
        if(cntr<x) continue;
        else
        {
            m=i;
            z=cntr-x;
            temp-=(z*(z+1))/2;
            break;
        }
    }
    ans=temp;
    //cout<<"i = 1    "<<temp<<endl;

    for(long long int i=2;i<=n;i++)
    {
        long long int v=d[i];
        temp+=((d[i])*(d[i]+1))/2;
        while(1)
        {
            if((d[m]-z)>=v)
            {
                temp+=(z*(z+1))/2;
                z+=v;
                temp-=(z*(z+1))/2;
                break;
            }
            else
            {
                v-=(d[m]-z);
                temp+=(z*(z+1))/2;
                z=d[m];
                temp-=(z*(z+1))/2;
                z=0;
                m++;
                if(m>n) m-=n;
            }
        }
        //cout<<"i = "<<i<<"    "<<temp<<endl;
        ans=max(ans,temp);
    }

    //cout<<endl;
    cout<<ans<<endl;
    return 0;
}