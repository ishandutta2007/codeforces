#include <iostream>

using namespace std;

int main()
{

    int n,gmax=0,ind=1,m,a[100],b[100];
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        a[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            int g=gmax;
            gmax=max(gmax,x);
            if (g!=gmax)
            {
                ind=j+1;
            }
        }
        gmax=0;
        a[ind-1]++;
        ind=1;

    }

    gmax=-1;
    ind=-1;

    for (int i=0;i<n;i++)
    {
        int g=gmax;
        gmax=max(a[i],gmax);
        if (g!=gmax)
        {
            ind=i+1;
        }
    }
    cout<<ind;
    return 0;
}