#include <iostream>
#define DMAX 620
using namespace std;

int m, t, r, w[DMAX], l[DMAX];

int main()
{
cin>>m>>t>>r;

    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        w[i]+=300;
    }

    // n=nr lumanari care mai trebuie aprinse aprinse
    // l[]=vector in care marchez cand aprind o lumanare
    // c=nr lumanari aprinse deja
    //
    //

    for(int i=1;i<=m;i++)
    {
        int c=0;
        //w[i]
        for(int j=1;j<=t;j++)
            if(l[w[i]-j]==1)
            c++;
        int n=r-c;
        int ci=w[i]-1;
        while(n)
        {
            if(l[ci]==0)
                l[ci]=1, n--;
            ci--;
            if(ci<w[i]-t && n>0)
            {
                cout<<-1;
            return 0;
            }
        }

    }
    int sol=0;
    for(int i=0;i<=DMAX;i++)
        sol+=l[i];
    cout<<sol;

    return 0;
}