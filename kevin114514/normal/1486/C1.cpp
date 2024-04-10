#include<bits/stdc++.h>
using namespace std;
int ask(int l,int r)
{
    cout<<"?"<<" "<<l<<" "<<r<<endl;
    int ret;
    cin>>ret;
    cout.flush();
    return ret;
}
void guess(int x)
{
    cout<<"!"<<" "<<x<<endl;
    exit(0);
}
int main()
{
    int n;
    cin>>n;
    int l=1,r=n;
    int smin=ask(l,r);
    while(l<r-1)
    {
        int mid=(l+r)/2;
        int lmin=ask(l,mid);
        int rmin=ask(mid,r);
        if(lmin==smin)
        {
            smin=lmin;
            r=mid;
        }
        else if(rmin==smin)
        {
            smin=rmin;
            l=mid;
        }
        else if(smin<mid)
        {
            smin=rmin;
            l=mid;
        }
        else
        {
            smin=lmin;
            r=mid;
        }
    }
    if(l==r-1)
    {
        guess(l+r-ask(l,r));
    }
    else
    {
        guess(l);
    }
    return 0;
}