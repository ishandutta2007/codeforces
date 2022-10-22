#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
double eps=1e-13;
double x[mn],y[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i;
    double w,v,u;
    cin>>n>>w>>v>>u;
    w/=u;
    bool gud=1;
    for(i=0;i<n;i++)cin>>x[i]>>y[i],x[i]/=v,y[i]/=u,x[i]-=y[i];
    for(i=0;i<n;i++){
        if(x[i]<=-eps)gud=0;
    }
    if(gud)printf("%.12f",w);
    else{
        double ad=0;
        for(i=0;i<n;i++){
            ad=max(ad,x[i]);
        }
        printf("%.12f",w+ad);
    }
}