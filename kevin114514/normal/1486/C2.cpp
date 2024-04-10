#include<bits/stdc++.h>
using namespace std;
int ask(int l,int r)
{
    printf("? %d %d\n",l,r);
    cout.flush();
    int ret;
    cin>>ret;
    return ret;
}
void guess(int x)
{
    printf("! %d\n",x);
    exit(0);
}
int main()
{
    int n;
    cin>>n;
    int smin=ask(1,n);
    if(smin==n||(smin>1&&ask(1,smin)==smin))
    {
        int l=1,r=smin-1;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(ask(mid,smin)==smin)
                l=mid;
            else    r=mid-1;
        }
        guess(l);
    }
    else
    {
        int l=smin+1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(ask(smin,mid)==smin)
                r=mid;
            else    l=mid+1;
        }
        guess(l);
    }
    return 0;
}