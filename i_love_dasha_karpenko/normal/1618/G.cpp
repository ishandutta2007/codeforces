#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
#define endl '\n'
#define all(var) var.begin(), var.end()
#define mp make_pair
#define gp(x,y) ((x-1)*m+y-1)
const int N = 4e5+7;
pair<int,int> A[N];
int P[N],cnt[N],R[N];
ll pref[N];
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
ll res = 0;
ll calc(int a){
    a = F(a);
    return pref[R[a]]-pref[R[a]-cnt[a]];
}
void unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b)
        return;
    res-=calc(a);
    res-=calc(b);
    P[b] = a;
    R[a] = max(R[a],R[b]);
    cnt[a]+=cnt[b];
    res+=calc(a);
}
ll ans[N];
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 1;i<=n;++i) {
        cin>>A[i].first;
        A[i].second = 0;
    }
    for(int i = n+1;i<=n+m;++i){
        cin>>A[i].first;
        A[i].second = 1;
    }
    sort(A+1,A+1+n+m);
    n+=m;
    vector<pair<int,int> > df(n-1);
    for(int i = 1;i<=n;++i){
        if (i>1)
        df[i-2] = {A[i].first-A[i-1].first,i};
        pref[i] = pref[i-1]+A[i].first;
        cnt[i] = 1-A[i].second;
        R[i] = i;
        P[i] = i;
        res+=calc(i);
        P[i] = i;
    }
    vector<pair<int,int> > Q(q);
    for(int i = 0;i<q;++i)
        cin>>Q[i].first,Q[i].second = i;
    sort(all(Q));
    sort(all(df));
    int ptr = 0;
    for(auto [dist,pos]:Q){
        while(ptr<df.size() && df[ptr].first<=dist){
            unite(df[ptr].second-1,df[ptr].second);
            ++ptr;
        }
        ans[pos] = res;
    }
    for(int i = 0;i<q;++i)
        cout<<(long long)(ans[i])<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}