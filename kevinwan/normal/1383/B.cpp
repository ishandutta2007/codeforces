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
const int mn=1e6+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int x=0;
        for(int i=0;i<n;i++)cin>>a[i],x^=a[i];
        if(!x){
            printf("DRAW\n");
            continue; 
        }
        x=1<<31-__builtin_clz(x);
        int num=0;
        for(int i=0;i<n;i++)if(a[i]&x)num++;
        int ans=((num/2+1)&1)|(n-num);
        if(ans&1)printf("WIN\n");
        else printf("LOSE\n");
    }
}