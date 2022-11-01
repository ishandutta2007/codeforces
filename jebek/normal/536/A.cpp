#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;

long long a,b,q,l,l1,r,t,m;

int main()
{
    cin>>a>>b>>q;
    for(int i=0;i<q;i++)
    {
        cin>>l1>>t>>m;
        if(l1*b+a-b>t)
        {
            cout<<-1<<endl;
            continue;
        }
        r=10000000;
        l=l1;
        while(l<r)
        {
            long long mid=(l+r+1)/2;
            if((mid-1)*b+a<=t && (mid-l1+1)*((l1+mid-2)*(b)+2*a)/2<=t*m)
                l=mid;
            else
                r=mid-1;
        }
        cout<<l<<endl;
    }
}