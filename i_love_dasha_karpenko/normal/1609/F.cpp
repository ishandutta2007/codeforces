#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
//#define gi(x) int(x-'a'+1);
const int N = 1e6+7;
const ll INF = 1e18+107;
const int LOG = 64;
ll A[N];
int clk[N],mod[N<<1];
pair<int,int> T[N<<1];
void push(int t,int nl,int nr){
    T[nl].first+=mod[t];
    T[nr].first+=mod[t];
    mod[nl]+=mod[t];
    mod[nr]+=mod[t];
    mod[t] = 0;
}
pair<int,int> merge(pair<int,int> a,pair<int,int> b){
    if (a.first>b.first)
        return a;
    if (b.first>a.first)
        return b;
    return mp(a.first,a.second+b.second);
}
void update(int t,int tl,int tr,int l,int r,int delta){
    if (tl>r || l>tr)
        return;
    if (l<=tl && tr<=r){
        T[t].first+=delta;
        mod[t]+=delta;
        return;
    }
    int tm = (tl+tr)>>1;
    int nl = t+1,nr = t+((tm-tl+1)<<1);
    push(t,nl,nr);
    update(nl,tl,tm,l,r,delta);
    update(nr,tm+1,tr,l,r,delta);
    T[t] = merge(T[nl],T[nr]);
}
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = mp(0,1);
        mod[t] = 0;
        return;
    }
    int tm = (tl+tr)>>1;
    int nl = t+1,nr = t+((tm-tl+1)<<1);
    buildtree(nl,tl,tm);
    buildtree(nr,tm+1,tr);
    T[t] = merge(T[nl],T[nr]);
    mod[t] = 0;
}
int L[2][N],R[2][N];
vector<int> bit_pos[LOG];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i) {
        cin >> A[i];
        clk[i] = __builtin_popcountll(A[i]);
        bit_pos[clk[i]].push_back(i);
    }
    stack<pair<ll,int> > Smin,Smax;
    Smin.push({-INF,0});
    Smax.push({INF,0});
    for (int i = 1; i <= n; ++i) {
        while (Smin.top().first >= A[i]) {
            int bnd = Smin.top().second;
            Smin.pop();
            R[0][bnd] = i;
        }
        while(Smax.top().first<=A[i]){
            int bnd = Smax.top().second;
            Smax.pop();
            R[1][bnd] = i;
        }
        L[0][i] = Smin.top().second+1;
        L[1][i] = Smax.top().second+1;
        Smin.push({A[i],i});
        Smax.push({A[i],i});
    }
    while(!Smin.empty()){
        R[0][Smin.top().second] = n+1;
        Smin.pop();
    }
    while(!Smax.empty()){
        R[1][Smax.top().second] = n+1;
        Smax.pop();
    }
    ll res = 0;
    buildtree(0,1,n);
    for(int bit = 0;bit<LOG;++bit) {
        vector<pair<int,pair<int,int> > > events(bit_pos[bit].size()*4);
        int ptr = 0;
        for(int pos:bit_pos[bit]){
            events[ptr++] = {pos,{pos,0}};
            events[ptr++] = {pos,{pos,1}};
            events[ptr++] = {R[0][pos],{-pos,0}};
            events[ptr++] = {R[1][pos],{-pos,1}};
        }
        sort(all(events));

        int prev = 0;
        for(auto [pos,elem]:events){
            if (T[0].first==2)
                res+=ll(T[0].second)*(pos-prev);
            prev = pos;
            int sg = 1;
            if (elem.first<0)
                sg = -1;
            update(0,1,n,L[elem.second][abs(elem.first)],abs(elem.first),sg);
        }
        if (T[0].first==2)
            res+=ll(T[0].second)*(n+1-prev);
    }
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;

    while(t--)
        solve();
}