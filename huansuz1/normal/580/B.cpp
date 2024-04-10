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
ll n,b[12345],c[12345],d[12345],k,ans,z,p,m;
pair< int , int > a[123456];
int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++) 
        cin>>a[i].f>>a[i].s;
    sort(a,a+n);
    p=0;
    m--;
    for (int i=0; i<n; i++) {
        if (a[i].f-a[p].f>m) {
            for (int j=p; j<=i; j++) 
                if (a[i].f-a[j].f<=m) {p=j; break;} else 
                z-=a[j].s;
        }

        z+=a[i].s; 
        //cout<<z<<endl;
        ans=max(z,ans);     
    }
    cout<<ans;

    

    return 0;
}