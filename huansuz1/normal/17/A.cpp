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


int n,k,a[1234],m,z,ans;
map<int,int> mp;



int main(){
cin>>n>>k;
a[z++]=2;
mp[2]=1;
for (int i=3; i<=n; i++) {
    int p=0;
    for (int j=2; j*j<=i; j++)
        if (i%j==0) { p=1; break; }
    if (p==0) { a[z++]=i; mp[i]=1; }
}
for (int i=0; i<z-1; i++) 
    if (mp[a[i]+a[i+1]+1]==1) ans++; 
if (ans>=k) cout<<"YES"; else cout<<"NO";

return 0;
}