#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 998244353;
const int inf = 0x3f3f3f3f;
const int maxn = 500030;
struct node{
    ll x,y;
    ll t;
}pos[maxn];
ll n,m,k,q;
ll mp[510][510];
ll a[510][510],b[510][510];
int cmp(struct node & a, struct node & b){
    return a.t<b.t;
}

int check(ll rr){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i = 1; pos[i].t<= rr&&i <= q ; i++){
        a[pos[i].x][pos[i].y] = 1;
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            b[i][j] = b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
        }
    }
    for(int i = k ; i <= n ; i++){
        for(int j = k; j <= m ; j++){
            if(b[i][j]+b[i-k][j-k]-b[i-k][j]-b[i][j-k] == k*k) return 1;
        }
    }
    return 0;
}

ll ans = -1;
ll Min = 1e10,Max = -1;

int main(){
    memset(mp,-1,sizeof(mp));
    scanf("%lld %lld %lld %lld",&n,&m,&k,&q);
    for(int i = 1; i <= q ; i++){
        scanf("%lld %lld %lld",&pos[i].x,&pos[i].y,&pos[i].t);
        mp[pos[i].x][pos[i].y] = pos[i].t;
        Min = min(Min,pos[i].t);
        Max = max(Max,pos[i].t);
    }
    sort(pos + 1 , pos + 1 + q ,cmp);
    ll l = Min , r = Max + 1;
    while(r - l > 0){
        ll mid = (r + l)/2;
        if(check(mid)){
            ans = mid;
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}