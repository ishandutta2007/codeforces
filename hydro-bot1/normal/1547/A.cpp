// Hydro submission #6274d686bda16328ffbb025a@1651824262762
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,xa,ya,xb,yb,xf,yf,s,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>xa>>ya>>xb>>yb>>xf>>yf;s=0;
        if(xa>xb||ya>yb) swap(xa,xb),swap(ya,yb);
        if(xa==xf&&xb==xf&&ya<yf&&yb>yf) s+=2;
        if(ya==yf&&yb==yf&&xa<xf&&xb>xf) s+=2;
        printf("%d\n",abs(xa-xb)+abs(ya-yb)+s);
    }
    return 0;
}