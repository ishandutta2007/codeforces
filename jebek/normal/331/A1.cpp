#include <iostream>
#include <vector>

using namespace std;

long long n,a[300000],MAX=-10000000000000000,l,r;
vector<long>p;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                long long k=a[i]+a[j];
                for(int u=j+1;u<i;u++)
                    if(a[u]>0)
                        k+=a[u];
                if(k>=MAX)
                {
                    MAX=k;
                    l=j;r=i;
                }
            }
        }
    }
    cout<<MAX<<" ";
    for(int i=0;i<n;i++)
    {
        if(i<l || i>r)
            p.push_back(i+1);
        if(i>l && i<r && a[i]<0)
            p.push_back(i+1);
    }
    cout<<p.size()<<endl;
    for(int i=0;i<p.size();i++)
        cout<<p[i]<<" ";
}