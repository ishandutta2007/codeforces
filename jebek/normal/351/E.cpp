#include <iostream>
#include<algorithm>

using namespace std;

long long n,a[3000],ans,k,MAX,f;
bool mark[3000],mark2[3000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            a[i]*=(-1);
    }
    while(k<n)
    {
        MAX=0;f=0;
        for(int i=0;i<n;i++)
            if(!mark[i])
                MAX=max(MAX,a[i]);
        for(int i=0;i<n;i++)
            if(a[i]==MAX)
            {
                mark2[i]=true;
                k++;
            }
        for(int i=0;i<n;i++)
        {
            if(mark2[i])
            {
                mark2[i]=false;
                mark[i]=true;
                if(f<=(n-k)/2)
                    a[i]=-a[i];
            }
            if(!mark[i])
                f++;
        }
    }
    //for(int i=0;i<n;i++)
     //   cout<<a[i]<<" ";
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i]<a[j])
                ans++;
    cout<<ans<<endl;
}