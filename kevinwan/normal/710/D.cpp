#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll gcd(ll a,ll b,ll&k,ll&l){
    if(a==0){l=-1,k=0;return b;}
    ll m=b/a,c=b-m*a;
    ll g=gcd(c,a,k,l);
    ll nk=(-l-k*m);
    l=-k,k=nk;
    return g;
}
ll fd(ll a,ll b){return a/b-((a^b)<0&&(a%b));}
ll mod(ll a,ll b){ll c=a%b;return c<0?c+b:c;}
ll _,__;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll a1,b1,a2,b2,l,r;
    cin>>a1>>b1>>a2>>b2>>l>>r;
    l=max(l,max(b1,b2));
    r=max(r,l-1);
    b1%=a1,b1+=a1,b1%=a1;
    b2%=a2,b2+=a2,b2%=a2;
    ll g=gcd(a1,a2,_,__);
    if(b1%g!=b2%g){printf("0");return 0;}
    l-=mod(b1,g),r-=mod(b1,g);
    a1/=g,a2/=g,b1/=g,b2/=g;
    l=fd(l-1,g)+1,r=fd(r,g);
    ll i1,i2;
    gcd(a1,a2,i1,i2);
    i2*=-1;
    ll p=a1*a2;
    __int128 one=1;
    ll num=(one*a1*i1%p*b2+one*a2*i2%p*b1)%p;
    if(num<0)num+=p;
    l-=num,r-=num;
    l=fd(l-1,p)+1,r=fd(r,p);
    printf("%lld\n",r-l+1);
}