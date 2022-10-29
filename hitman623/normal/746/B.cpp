#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i=0,l=0;
    cin>>n;
    char a[2001],b[2001];
    cin>>a;
    while(l<n)
    {
        b[(n-1)/2+(((l+n+1)&1)?-i:i)]=a[l];
        if(l%2==0) i++;
        l++;
        //cout<<l;
    }
    b[l]='\0';
    cout<<b;
    return 0;
}