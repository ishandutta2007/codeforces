#include <iostream>

#define DMAX 100005

using namespace std;

int n, a[DMAX], lmax, r[DMAX], l[DMAX];

void right()
{
    r[n]=1;
    for(int i=n-1; i>0; --i)
    {
        if(a[i]<a[i+1])
            r[i]=r[i+1]+1;
        else r[i]=1;
    }
}

void left()
{
    l[1]=1;
    for(int i=2; i<=n; ++i)
    {
        if(a[i]>a[i-1])
            l[i]=l[i-1]+1;
        else l[i]=1;
    }
}

void solve()
{
    for(int i=1; i<=n; i++)
    {
        if(a[i-1]<a[i+1]-1)
        {
            if(l[i-1]+r[i+1]+1>lmax)
                lmax=l[i-1]+r[i+1]+1;

        }
        else{
            if(l[i-1]+1>lmax)
                lmax=l[i-1]+1;

            if(r[i+1]+1>lmax)
                lmax=r[i+1]+1;
        }
    }

    cout<<lmax<<'\n';

    //if(a[1]>a[2] && r[2]+1>lmax)
      //  lmax=r[2]+1;

    //if(a[n-1]>a[n] && l[2]+1>lmax)
        //lmax=l[n-1]+1;


}

int main()
{
    cin>>n;

    if(n==1)
    {
        cout<<1<<'\n';
        return 0;
    }

    for(int i=1; i<=n; i++)
        cin>>a[i];

    right();

    left();

    solve();

    return 0;
}