#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x=0,y=0,z=0,n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        x+=a;
        y+=b;
        z+=c;
    }
    if(x==0 && y==0 && z==0)cout<<"YES";
    else cout<<"NO";
        }