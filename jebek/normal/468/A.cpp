#include <iostream>

using namespace std;

long long n,sum;

int main()
{
    cin>>n;
    if(n<4)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(n%4==1)
    {
        cout<<"5 - 1 = 4\n";
        cout<<"4 - 2 = 2\n";
    }
    if(n%4==3)
    {
        cout<<"7 - 6 = 1\n";
        cout<<"5 - 1 = 4\n";
        cout<<"4 - 2 = 2\n";
        cout<<"2 * 1 = 2\n";
    }
    cout<<"2 * 3 = 6\n";
    cout<<"6 * 4 = 24\n";
    sum=24;
    if(n%4==0)
    {
        cout<<"1 * 24 = 24\n";
        for(int i=5;i<=n;i++)
        {
            if(i%4==1 || i%4==0)
            {
                cout<<sum<<" + "<<i<<" = "<<sum+i<<'\n';
                sum+=i;
            }
            else
            {
                cout<<sum<<" - "<<i<<" = "<<sum-i<<'\n';
                sum-=i;
            }
        }
    }
    if(n%4==1)
    {
        for(int i=6;i<=n;i++)
        {
            if(i%4==1 || i%4==2)
            {
                cout<<sum<<" + "<<i<<" = "<<sum+i<<'\n';
                sum+=i;
            }
            else
            {
                cout<<sum<<" - "<<i<<" = "<<sum-i<<'\n';
                sum-=i;
            }
        }
    }
    if(n%4==2)
    {
        for(int i=5;i<=n;i++)
        {
            if(i%4==1 || i%4==0)
            {
                cout<<sum<<" + "<<i<<" = "<<sum+i<<'\n';
                sum+=i;
            }
            else
            {
                cout<<sum<<" - "<<i<<" = "<<sum-i<<'\n';
                sum-=i;
            }
        }
        cout<<sum<<" + 1 = "<<sum+1<<'\n';
    }
    if(n%4==3)
    {
        for(int i=8;i<=n;i++)
        {
            if(i%4==3 || i%4==0)
            {
                cout<<sum<<" + "<<i<<" = "<<sum+i<<'\n';
                sum+=i;
            }
            else
            {
                cout<<sum<<" - "<<i<<" = "<<sum-i<<'\n';
                sum-=i;
            }
        }
    }
}