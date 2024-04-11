#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define fi first
#define se second

using namespace std;

int a[100500];
    int l,r;
int q;
main()
{
    q=0;
    int n;
    cin>>n;
    n+=2;
    a[1]=0;
    a[n]=1e9;
    for (int i=2; i<n; i++)
        cin>>a[i];
    //cout<<a[1]<<a[2]<<a[3]<<a[4]<<a[5];
    for (int i=1; i<n; i++)
    {
        //cout<<a[i]<<" "<<a[i+1]<<"\n";
        if (a[i]>a[i+1])
        {
            l=i;
            break;
        }
    }
    for (int i=n; i>1; i--)
    {
        if (a[i]<a[i-1])
        {
            r=i;
        break;
        }
    }
   // cout<<l<<" "<<r<<"\n";
    if (l==0)
    {
        cout<<"yes\n1 1\n";
        exit(0);
    }
    for (int i=l; i<=(r+l)/2; i++)
        swap(a[i], a[r+l-i]);
    for (int i=1; i<n; i++)
    if (a[i]>a[i+1])
    {
        cout<<"no\n";
        exit(0);
    }
    cout<<"yes\n"<<l-1<<" "<<r-1<<"\n";
}