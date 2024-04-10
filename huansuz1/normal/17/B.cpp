#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
//#define mp make_pair
#define f first
#define s second

using namespace std;


int n,q[1234],m,a[12345],b[12345],c[12345],d[1234], ans , z;


int main(){
cin>>n;
for (int i=1; i<=n; i++){
    cin>>q[i];
    d[i]=-1;
}
cin>>m;
for (int i=0; i<m; i++){
    cin>>a[i]>>b[i]>>c[i];
    if (q[a[i]]>q[b[i]] && d[b[i]]==-1) d[b[i]]=c[i]; else 
        if (q[a[i]]>q[b[i]] && d[b[i]]!=-1) d[b[i]]=min(c[i],d[b[i]]); 
}
for (int i=1; i<=n; i++) 
    if (d[i] != -1) ans+=d[i]; else z++;    

if (z!=1) {cout<<-1; return 0;}
cout<<ans;

return 0;
}