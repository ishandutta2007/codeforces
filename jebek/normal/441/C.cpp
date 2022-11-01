#include <iostream>
#include<algorithm>

using namespace std;

int n,m,k,x,y;

void check(int x1)
{
    for(int i=x1;i<=n;i++)
    {
        cout<<m<<" ";
        for(int j=1;j<=m;j++)
            cout<<i<<" "<<j<<" ";
        cout<<endl;
    }
}

int main()
{
    cin>>n>>m>>k;
    x=1;y=1;
    if(k<n)
    {
        for(int i=1;i<k;i++)
        {
            cout<<m<<" ";
            for(int j=1;j<=m;j++)
                cout<<i<<" "<<j<<" ";
            cout<<endl;
        }
        cout<<(n-k+1)*m<<" ";
        for(int i=k;i<=n;i++)
        {
            if(i%2==0)
            {
                for(int j=1;j<=m;j++)
                    cout<<i<<" "<<j<<" ";
            }
            else
            {
                for(int j=m;j>0;j--)
                    cout<<i<<" "<<j<<" ";
            }
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        if(x%2==1)
        {
            if(y==m)
            {
                cout<<2<<" "<<x<<" "<<y<<" "<<x+1<<" "<<y<<endl;
                x=x+1;
                y=y-1;
                continue;
            }
            if(k-i==n-x)
            {
                cout<<m-y+1<<" ";
                for(int j=y;j<=m;j++)
                    cout<<x<<" "<<j<<" ";
                cout<<endl;
                check(x+1);
                return 0;
            }
            cout<<2<<" "<<x<<" "<<y<<" "<<x<<" "<<y+1<<endl;
            y+=2;
            if(y==m+1)
            {
                x++;
                y=m;
            }
        }
        else
        {
            if(y==1)
            {
                cout<<2<<" "<<x<<" "<<y<<" "<<x+1<<" "<<y<<endl;
                x=x+1;
                y=y+1;
                continue;
            }
            if(k-i==n-x)
            {
                cout<<y<<" ";
                for(int j=1;j<=y;j++)
                    cout<<x<<" "<<j<<" ";
                cout<<endl;
                check(x+1);
                return 0;
            }
            cout<<2<<" "<<x<<" "<<y<<" "<<x<<" "<<y-1<<endl;
            y-=2;
            if(y==0)
            {
                x++;
                y=1;
            }
        }
    }
}