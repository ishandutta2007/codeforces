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

int n,a[123],ok[123],ans,l,r,x;
void rec(int v){
    if (v>n) {
        int z=0,mx=0,mi=10000009;
        long long sum=0;
        for(int i=1; i<=n; i++) 
            if(ok[i]) {z++; sum+=a[i];mx=max(mx,a[i]); mi=min(mi,a[i]);}
        if (z>=2 && sum>=l && sum<=r && mx-mi>=x) ans++;
        return;
    
    }
    ok[v]=1;
    rec(v+1);
    ok[v]=0;
    rec(v+1);
}


int main(){   
cin>>n>>l>>r>>x;
for (int i=1; i<=n; i++)
    cin>>a[i];

rec(1);
cout<<ans;




}