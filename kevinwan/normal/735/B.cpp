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
double v[mn];

int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v,v+n,greater<>());
    if(a>b)swap(a,b);
    double s1=0,s2=0;
    for(int i=0;i<a;i++)s1+=v[i];
    for(int i=0;i<b;i++)s2+=v[a+i];
    printf("%.20lf",s1/a+s2/b);
}