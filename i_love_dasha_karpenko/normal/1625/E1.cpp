//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 3e5+7;
const int INF = 1e9+7;
int pref[N],last[N<<1],T[N<<1],nxt[N],pr[N];
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = pref[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    buildtree(t+1,tl,tm);
    buildtree(t+((tm-tl+1)<<1),tm+1,tr);
    T[t] = min(T[t+1],T[t+((tm-tl+1)<<1)]);
}
int get(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return INF;
    if (l<=tl && tr<=r)
        return T[t];
    int tm = (tl+tr)>>1;
    return min(get(t+1,tl,tm,l,r),get(t+((tm-tl+1)<<1),tm+1,tr,l,r));
}
struct query{
    int l,r,pos;
};
const int BL_SZ = 600;
vector<query> Q[N/BL_SZ+7];
bool mc(query &a,query &b){
    return a.r<b.r;
}
ll ans[N];
ll beg[N],len[N];
void add(int pos,int lb,ll &res){

    if (pr[pos]<lb)
        return;
    beg[pos] = beg[pr[pos]-1];
    beg[pos] = beg[pos]==0?pr[pos]:beg[pos];
    ++len[beg[pos]];
    res+=len[beg[pos]];
}
ll stup(int l,int r,int mxr){
    ll ret = 0;
    for(int i = r;i>=l;--i){
        len[i] = 0;
        if (nxt[i]==0 || nxt[i]>mxr)
            continue;
        len[i] = len[nxt[i]+1]+1;
        ret+=len[i];
    }
    return ret;
}
void solve() {
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        char ch; cin>>ch;
        pref[i] = pref[i-1] + (ch=='('?1:-1);
    }
    buildtree(0,1,n);
    for(int i = n;i>=1;--i){
        nxt[i] = last[pref[i-1]+N];
        nxt[i] *= (get(0,1,n,i,nxt[i])>=pref[i-1]);
        pr[nxt[i]] = i;
        last[pref[i]+N] = i;
    }
    int dum;
    for(int i = 0;i<q;++i){
        query cur;
        cin>>dum>>cur.l>>cur.r;
        cur.pos = i;
        Q[(cur.l-1)/BL_SZ].push_back(cur);
    }
    for(int bl = 0;bl*BL_SZ+1<=n;++bl){
        for(int i = 1;i<=n;++i)
            beg[i] = len[i] = 0;
        int lb = bl*BL_SZ+1,rb = min(lb+BL_SZ-1,n);
        sort(all(Q[bl]),mc);
        int cr = rb;
        ll res = 0;
        for(auto [l,r,pos]:Q[bl]){

            while(cr<r){
                ++cr;
                add(cr,rb+1,res);
            }
            ans[pos] = res+stup(l,min(r,rb),r);
        }
    }
    for(int i = 0;i<q;++i)
        cout<<ans[i]<<endl;
}

signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}