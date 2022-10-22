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
const int mn=1e5+10;
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
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        bool done=0;
        for(int i=2;i*i<=n;i++)if(n%i==0){
            done=1;
            printf("%d %d\n",n/i,n-n/i);
            break;
        }
        if(!done)printf("1 %d\n",n-1);
    }
}