#include<iostream>

using namespace std;

int main()
{
    int a,b;
    long n,m,l,r,k=0,h=0,t;
    cin>>n>>m;
    for(long i=0;i<n;i++)
    {
        cin>>a;
        if(a==-1)
            k++;
        else
            h++;
    }
    for(long i=0;i<m;i++)
    {
        cin>>l>>r;
        b=(r-l)%2;
        if(b==0)
            cout<<"0"<<endl;
        else
        {
            t=(r-l+1)/2;
            if((k>=t)&&(h>=t))
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
    }
}