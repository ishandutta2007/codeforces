#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a[n+1],temp;
    int mx=0,pos[31]={0},freq[31]={0},u;
    for(int i=1;i<n+1;i++)
    {
        cin>>a[i];
        long int x=a[i];
        int cntr=0;
        for(int j=1;j<31;j++)
        {
            if(x%2==1)
            {
                pos[j]=i;
                freq[j]++;
            }
            x/=2;
            cntr++;
            if(x==0) break;
        }
        mx=max(mx,cntr);
    }
    for(u=mx;u>0;u--) if(freq[u]==1) break;
    int mxi;
    if(u==0) mxi=1;
    else mxi=pos[u];
    swap(a[1],a[mxi]);
    for(int i=1;i<n+1;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}