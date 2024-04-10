#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 100020;
ll v[MAXN];
ll N;
ll ls[MAXN];
ll segt[262144];
void upd(int pos, ll val){
    pos+=131072;
    segt[pos] = min(segt[pos],val);
    pos/=2;
    while(pos){
        segt[pos] = max(segt[2*pos],segt[2*pos+1]);
        pos/=2;
    }
}
ll query(ll a){
    if(a == 0)return 100000000;
    ll ans = 0;
    a+=131072;
    int b = 131072;
    while(b <= a){
        if(b & 1)ans = max(ans,segt[b]);
        b++;
        if((a & 1) == 0)ans = max(ans,segt[a]);
        a--;
        a/=2; b/=2;
    }
    return ans;
}
bool poss[MAXN];
int main(){
    cin >> N;
    for(int i = 0; i < 262144; i++)segt[i]=100000000;
    upd(0,0);
    for(int i = 0; i < N; i++)cin >> v[i];
    for(int i = 0; i < MAXN; i++)ls[i]=100000000;
    for(int i = N-1; i>= 0; i--){
        if(v[i]>1)poss[1]=1;
        if(query(v[i]-1)<ls[v[i]])poss[v[i]]=1;
    //    cout << "q "<<query(v[i]-1)<<"\n";
        ls[v[i]] = i;
        upd(v[i],i);
    }
    for(int i = 1; i <= N+1; i++){
        if(query(i-1)<ls[i])poss[i]=1;
    //    cout << "q "<<query(i-1)<<"\n";
    }
    for(int i = 1; i < MAXN; i++)if(poss[i]==0){cout << i << "\n"; return 0;}
    return 0;
}