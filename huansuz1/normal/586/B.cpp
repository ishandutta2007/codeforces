#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair                                                        
#define ll long long

using namespace std;

priority_queue < pair < ll, ll > > q;
map< ll , ll > m;
ll n,a[1023],c[1234],z,b[1234],x[1234],y[1234],mi=1000000,ans,p,d[1234];

int main(){
    cin>>n;
    for (int i=1; i<n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
        cin>>b[i];
    for (int i=0; i<n; i++)
        cin>>c[i];

    x[0]=0;y[0]=0;
    for (int i=1; i<n; i++) {
        x[i]=x[i-1]+a[i];
    //  cout<<a[i]<<" ";
    }
    
    for (int i=n-1; i>=1; i--)  {
        y[i]=y[i+1]+b[i];
        //cout<<a[i]<<" ";   
    }
    
    mi=min(x[n-1]+c[n-1] ,  y[1]+c[0]);
    d[0]=c[0]+y[1];
    d[n-1]=x[n-1]+c[n-1];
    mi=min(d[0],d[n-1]);
    p=0;
    if (d[0]>d[n-1])  p=n-1;
    
    for (int i=1; i<n-1; i++)  {
        d[i]=10000000;
        d[i]=min((x[i]+y[i+1]+c[i]), d[i]);     
        if (d[i]<mi) {mi=d[i]; p=i;}
    }
        
 
    ans+=mi;
    d[p]=10000001;
    mi=min(d[0],d[n]);
    p=0;    
    mi=10000000;
    for (int i=0; i<n; i++) { 
        if (d[i]<mi) mi=d[i]; 

    }

    ans+=mi;
    cout<<ans;
        



    





    return 0;
}