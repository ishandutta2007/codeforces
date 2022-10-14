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
ll N;
const int MAXN = 200100;
int fenwick[MAXN];
void update(int pos, int delta){
    for(;pos < MAXN; pos+=pos&-pos)fenwick[pos]+=delta;
}
int query(int pos){
    int res = 0;
    for(; pos>0; pos-=pos&-pos)res+=fenwick[pos];
    return res;
}
int main(){
    cin >> N;
    string s;
    cin >> s;
    for(auto &x: s)x-='a';
    vi v[30], rv[30];
    for(int i = 0; i < N; i++){v[s[i]].pb(i);rv[s[i]].pb(N-1-i);}
    ll ans = 0;
    vi vv(N);
    for(int i = 0; i < 30; i++){
        reverse(rv[i].begin(),rv[i].end());
        for(int j = 0; j < v[i].size(); j++){
            vv[v[i][j]] = rv[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        ans+=i-query(vv[i]+1);
        update(vv[i]+1,1);
    }
    cout << ans  <<"\n";
    return 0;
}