#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,cntr1=0;
        cin>>n;
        int k1=n,k2=-1;
        long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<i && cntr1==0)
            {
                k1=i;
                cntr1++;
            }
            if(a[i]<n-1-i) k2=i;
        }
        if(k1>k2+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        t--;
    }
    return 0;
}