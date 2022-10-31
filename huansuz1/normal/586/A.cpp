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
ll n,a[1023456],z,x,y,ans;

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++) {
        if (a[i]==0) z++; else {
            if (z>=2) ans+=z; 
            z=0;    
        }
    }
    
    if (a[0]==0 && a[1]==1) ans++;
    ans+=z;
    cout<<n-ans;







    return 0;
}