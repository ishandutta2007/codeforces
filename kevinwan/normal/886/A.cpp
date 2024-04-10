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
const int mn=1e5+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[6];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tot=0;
    for(int i=0;i<6;i++)cin>>a[i],tot+=a[i];
    for(int i=0;i<6;i++)for(int j=i+1;j<6;j++)for(int k=j+1;k<6;k++){
        if((a[i]+a[j]+a[k])*2==tot){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}