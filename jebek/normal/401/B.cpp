#include <iostream>
#include<algorithm>

using namespace std;

long long n,k,a,t,ans,ans1;
bool mark[5000];

int main()
{
    cin>>k>>n;
    mark[k]=true;
    for(int i=0;i<n;i++)
    {
        cin>>t>>a;
        mark[a]=true;
        if(t==1)
        {
            cin>>a;
            mark[a]=true;
        }
    }
    for(int i=1;i<k;i++)
    {
        if(!mark[i])
        {
            ans++;
            if(!mark[i+1])
            {
                ans1++;
                ans++;
                mark[i+1]++;
            }
        }
    }
    cout<<ans-ans1<<" "<<ans<<endl;
}