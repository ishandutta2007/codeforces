#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=1e6+10;
const ll mod=1e9+7;

int n,k,turn;
int query(int x){
    turn++;
    printf("? %d\n",x+1);
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}

void report(int x){
    printf("! %d\n",x+1);
    fflush(stdout);
    exit(0);
}

void bs(int x,int v){
    int t=turn;
    if(v>k){
        for(int i=1<<9;i;i>>=1){
            if(i>min(t,n/2))continue;
            int cand=(x-i+n)%n;
            int v=query(cand);
            if(v==k)report(cand);
            else if(v>k)x=cand;
        }
        report(x);
    }
    else{
        for(int i=1<<9;i;i>>=1){
            if(i>min(t,n/2))continue;
            int cand=(x+i)%n;
            int v=query(cand);
            if(v==k)report(cand);
            else if(v<k)x=cand;
        }
        report(x);
    }
}

int main(){
#ifdef LOCAL
//    freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin>>n>>k;
    for(int i=0;i<250;i++)query(0);
    for(int i=0;i+1<n;i+=400){
        int v=query(i),v2=query(i+1);
        if(v!=k)bs(i,v);
        else if(v2!=k)bs(i+1,v2);
        else continue;
        return 0;
    }
}