#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;

string s;
ll a,b,c,a1,b1,c1,x,y,z,ss;
ll r,ans;

int main(){
    cin>>s;
    cin>>a>>b>>c;
    cin>>a1>>b1>>c1;
    cin>>r;
    for (int i=0; i<s.length(); i++)
        if (s[i]=='B') x++; else
        if (s[i]=='S') y++; else
        z++;
    if (x==0) a=0;
    if (y==0) b=0;
    if (z==0) c=0;
    while(a!=0 || b!=0 || c!=0){
        if (a>=x) a-=x; else 
            if ((x-a)*a1<=r) {r-=((x-a)*a1); a=0; } else break; 
        if (b>=y) b-=y; else 
            if ((y-b)*b1<=r) {r-=((y-b)*b1); b=0; } else break;
        if (c>z) c-=z; else 
            if ((z-c)*c1<=r) {r-=((z-c)*c1); c=0; } else break;
        ans++;
    }
    ans+=(r/((x*a1)+(y*b1)+(z*c1)));
    cout<<ans;
    

      

    return 0;
}