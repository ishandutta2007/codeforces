//Problem B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c,d;
ll gcd(ll a,ll b){if(b)return gcd(b,a%b);return a;}
int main(){
    cin>>a>>b>>c>>d;
    ll g=gcd(c,d);
    c/=g,d/=g;
    cout<<min(a/c,b/d);
    return 0;
}