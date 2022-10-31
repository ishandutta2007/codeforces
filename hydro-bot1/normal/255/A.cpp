// Hydro submission #6253c95b48f783013279207c@1649658204224
#include<bits/stdc++.h>
using namespace std;
int a[20],t,s,k,mx;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        switch(i%3)
        {
            case 0:t+=a[i];break;
            case 1:s+=a[i];break;
            case 2:k+=a[i];break;
        }
    }
    mx=max(max(t,s),k);
    if(t==mx) printf("chest\n");
    if(s==mx) printf("biceps\n");
    if(k==mx) printf("back\n");
    return 0;
}