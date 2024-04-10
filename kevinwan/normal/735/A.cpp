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
    int n,m;
    cin>>n>>m;
    int s,e;
    string p;
    cin>>p; 
    for(int i=0;i<n;i++){
        if(p[i]=='G')s=i;
        if(p[i]=='T')e=i;
    }
    if((e-s)%m){printf("NO\n");return 0;}
    if(e>s){for(int i=s;i<=e;i+=m)if(p[i]=='#'){printf("NO\n");return 0;}}
    else{ for(int i=s;i>=e;i-=m)if(p[i]=='#'){printf("NO\n");return 0;}}
    printf("YES\n");
}