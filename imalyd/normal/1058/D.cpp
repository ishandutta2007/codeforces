//Problem D
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
#define ll long long
ll n,m,k;
ll gcd(ll a,ll b){if(b)return gcd(b,a%b);return a;}
#define NO {cout<<"No";return 0;}
int main(){
    cin>>n>>m>>k;
    ll x=n*m*2;
    if(x%k)NO
    x/=k;
    ll a,b;
    if(gcd(2*n,k)==1)b=2*m/gcd(2*m,k),a=x/b;
    else a=2*n/gcd(2*n,k),b=x/a;//printf("QAQ\n");
    ll g=gcd(a,b);
    ll c=x/(a/g*b);
    cout<<"Yes\n0 0\n"<<a<<" 0\n0 "<<b;
    return 0;
}