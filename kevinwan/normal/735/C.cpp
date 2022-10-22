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
ll num[mn];
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
    cin>>n;
    num[0]=1;
    num[1]=2;
    //if(n==2){printf("1");return 0;}
    for(int i=2;1;i++){
        num[i]=num[i-1]+num[i-2];
        if(num[i]>n){
            printf("%d",i-1);
            return 0;
        }
    }
}