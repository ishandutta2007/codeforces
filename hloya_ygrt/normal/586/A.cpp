#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    int n,a[100],s=0,l=0;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        if (s==0&&x==0) continue;
        if (s==0&&x==1)
        {
            a[l]=x;
            l++;
            s=1;
        } else
        {
            a[l]=x;
            l++;
        }

    }
    l--;
    int l1=l;
    if (l==-1)
    {
        cout<<0;
        return 0;

    }

    for (int i=l1;i>0;i--)
    {
        if (a[i]==0)
            l--;
        else break;
    }
    s=1;
    int ans=1;
    for (int i=0;i<l;i++)
    {
        if (a[i]==1)
        {
            ans++;
            s=1;
        }
        if (a[i]==0&&s==1)
        {
            if (a[i+1]!=0)
            ans++;
            else {
                s=0;
            }
        }

    }
    cout<<ans;
    return 0;
}