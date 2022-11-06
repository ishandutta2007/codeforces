//Problem B
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int q;
ll n,a,b,u;

int main(){
    cin>>n>>q;
    while(q--){
        cin>>a>>b,u=0;
        int f=((n|a)&1ll)^1;
        a=(a-1)*n+b;
        if(f){
            if(a&1)++a;
            else --a;
        }
        u=(a+1)>>1;
        if(!(a&1))u+=(n*n+1)/2;
        cout<<u<<endl;
    }
    return 0;
}