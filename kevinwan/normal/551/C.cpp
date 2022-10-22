#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
int n,m;
ll a[mn],b[mn];
bool check(ll x){
    int pos=n,i;
    memcpy(b,a,sizeof(a));
    for(i=0;i<m;i++){
        while(pos&&!b[pos])pos--;
        if(pos==0)return 1;
        ll rem=x-pos;
        while(pos&&rem>=b[pos]){
            rem-=b[pos];
            b[pos]=0;
            pos--;
        }
        b[pos]-=rem;
    }
    return pos==0;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    ll cur=0;
    for(ll i=1LL<<50;i;i>>=1){
        if(!check(cur+i))cur+=i;
    }
    cout<<cur+1;
}