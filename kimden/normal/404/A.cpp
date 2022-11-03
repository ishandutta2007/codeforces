#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int i,j,n;
    char c,d;
    bool b=true;
    cin>>n;
    string k;
    for(i=0;i<n;i++)
    {
        cin>>k;//getline(cin,k);
        if(i==0)
        {
            c=k[0];
          //  cout<<"c="<<c<<endl;
            d=k[1];
           // cout<<"d="<<d<<endl;
        }
        for(j=0;j<n;j++)
        {
            if((i==j)||(i+j==n-1))
            {
                if(k[j]!=c) b=false;
            }else if(k[j]!=d) b=false;
             //   cout<<i<<'\t'<<j<<'\t'<<(int)(i==j)<<(int)(i+j==n-1)<<(int)(k[j]!=c)<<'\t'<<(int)(k[j]!=d)<<endl;
        }
    }
    if(((b) && (c!=d)) && (n%2==1))
    {
        cout<<"YES";
    }else
    {
        cout<<"NO";
    }
    return 0;
}