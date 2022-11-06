//Problem B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll sum(ll a){
    ll b=0;
    while(a)b+=a%10,a/=10;
    return b;
}
int main(){
    cin>>n;
    while(m<=n)m=m*10+9;
    m/=10;//cout<<m<<" ";
    cout<<sum(m)+sum(n-m);
    return 0;
}