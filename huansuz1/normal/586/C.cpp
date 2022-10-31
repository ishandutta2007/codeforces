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
ll n,a[10234],b[12345],c[12345],d[12345],k,ans[12345],z,p;
int main(){
    cin>>n;
    for (int i=0; i<n; i++) 
        cin>>a[i]>>b[i]>>c[i];

    for (int i=0; i<n; i++) {
       // cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl; 
        if (d[i]) continue;
        ans[z++]=i;
        k=a[i];
        for (int j=i+1; j<n; j++) 
            if (!d[j] && k>0) {
                c[j]-=k;
                k--;
            }
        ll sum=0;
        for (int j=i+1; j<n; j++) 
            if (!d[j]) {
                c[j]-=sum;
                if (c[j]< 0) {
                d[j]=1;
                    sum+=b[j];
                } 
            }
     
    }
        
    
    cout<<endl;
        cout<<z<<endl;
    if (z!=0) {
        for (int i=0; i<z; i++)
            cout<<ans[i]+1<<" ";
    }




    return 0;
}