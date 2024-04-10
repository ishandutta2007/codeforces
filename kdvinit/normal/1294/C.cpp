/*
1 - Use Cmath for sqrt(int n);
2 - pow(a,b) also in cmath

*/

#include <cmath>
#include <iostream>
using namespace std;

void show(long int a[],int strt,int nd)
{
    for(int i=strt;i<=nd;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long int n;
        cin>>n;
        if(n<24) { cout<<"NO"<<endl; t--; continue; }
        int x;
        x = sqrt(n);
        int prime[x]={0},cntr1=0,cntr2=0,p1;
        for(int i=2;i<x+1;i++)
        {
            int j=1;
            for(j=1;prime[j]*prime[j]<=i && j<=cntr1;j++)
            {
                if(i%prime[j]==0) break;
            }
            if(j>cntr1 || prime[j]*prime[j]>i) prime[++cntr1]=i;
        }
        //show(prime,1,cntr);
        for(x=1;x<=cntr1;x++)
        {
            int z=prime[x];
            if(n%z==0)
            {
                if(cntr2==0)
                {
                    if (n%(z*z*z*z*z*z)==0) { cout<<"YES"<<endl<<z<<" "<<z*z<<" "<<n/(z*z*z)<<endl; break; }
                    else if(n%(z*z*z)==0)
                    {
                        if(n!=z*z*z*z*z && n!=z*z*z*z && n!=z*z*z) { cout<<"YES"<<endl<<z<<" "<<z*z<<" "<<n/(z*z*z)<<endl; break; }
                    }
                    else { cntr2++; p1=z; }
                }
                else if(cntr2==1 && n/(p1*z)!=p1 && n/(p1*z)!=z) {cout<<"YES"<<endl<<p1<<" "<<z<<" "<<n/(z*p1)<<endl; break;}
            }
        }
        if(x>cntr1) cout<<"NO"<<endl;
        t--;
    }
    return 0;
}