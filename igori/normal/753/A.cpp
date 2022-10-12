#include <iostream>

using namespace std;

int main()
{
     int n;
     cin>>n;
     int k=0;
     int i=1;
     int s=0;

     while(k<n)
     {
        k=k+i;
        i++;
     }
     if(k!=n)
     {i--;
     i--;
     cout<<i<<endl;
     for(int c=1; c<i; c++)
        {cout<<c<<" ";s=s+c;}
    cout<<n-s;}
    if(k==n)
    {
        i--;
        cout<<i<<endl;
        for(int c=1; c<i+1; c++)
        {cout<<c<<" ";}
    }

}