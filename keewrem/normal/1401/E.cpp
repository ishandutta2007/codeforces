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

int T;
ll N,M;
int fenwick[1000002];
void update(int pos, int delta){
    for(;pos < 1000002; pos+=pos&-pos)fenwick[pos]+=delta;
}
int query(int pos){
    int res = 0;
    for(; pos>0; pos-=pos&-pos)res+=fenwick[pos];
    return res;
}
int a,b,c;
int main(){
    cin >> N >> M;
    vector<pair<int,pii>> q;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        q.pb({b,{0,a}});
        q.pb({c,{3,a}});
    }
    ll ans = 1;
    for(int i = 0; i < M;i++){
        cin >> a >> b >> c;
        if(c-b == 1000000)ans++;
        if(b == 0)q.pb({a,{1,c}});
        else q.pb({a,{2,b}});
    }
    q.pb({1000000,{1,1000000}});q.pb({0,{1,1000000}});
    sort(q.begin(),q.end());
    ans-=N;
    for(auto x: q){
        if(x.se.fi == 0)update(x.se.se,1);
        if(x.se.fi == 1)ans += query(x.se.se);
        if(x.se.fi == 2)ans += query(1000000)-query(x.se.se-1);
        if(x.se.fi == 3)update(x.se.se,-1);
    }
    cout << ans<<"\n";
    return 0;
}