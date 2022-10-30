#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;
string s;
int n,m,k,p,x=123345,ans,y,xx=123435,yy,q=0;
int main(){
    cin>>k>>p;
    cin>>s;
    s=' '+s;
    for (int i=1; i+i<=k; i++)
        if (s[i]!=s[k-i+1]) {
            q=1;
            x=min(i,x);
            y=max(i,y);
            xx=min(k-i+1,xx);
            yy=max(k-i+1,yy);
            ans+=min(abs(s[i]-s[k-i+1]),abs(min(s[k-i+1],s[i])+26-max(s[k-i+1],s[i])));
        }
    if (!q){
        cout<<0;
        return 0;
    
    }
    if (p<=k/2){
        if (p>=x && p<=y) 
            ans+=min(abs(p-x),abs(p-y))+y-x;
            else 
            if (p<=x) 
                ans+=y-p; 
                else 
                ans+=p-x;
    } else {
        x=xx;
        y=yy;
        if (p>=x && p<=y) 
            ans+=min(abs(p-x),abs(p-y))+y-x;
            else 
            if (p<=x) 
                ans+=y-p; 
                else 
                ans+=p-x;
    }
    cout<<ans;

    
        


    return 0;
}