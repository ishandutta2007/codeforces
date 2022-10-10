#include<bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m,T;
int main(){
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        //x=y+a
        //y=z+b
        //z=c
        ll x,y,z;
        z=c;y=z+b;x=y+a;
        cout<<x<<' '<<y<<' '<<z<<endl;
    }
}