#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    ll n;
    char c;
    scanf("%lld%c",&n,&c);
    n--;
    ll ans=(n/4)*16+(n%2)*7;
    if(c=='f')ans++;
    else if(c=='e')ans+=2;
    else if(c=='d')ans+=3;
    else if(c=='a')ans+=4;
    else if(c=='b')ans+=5;
    else ans+=6;
    printf("%lld",ans);
}